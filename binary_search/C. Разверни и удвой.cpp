#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<deque>
#include<map>
#include<unordered_map>
#include<string>
#include<cstring>
#include<stack>
#include<vector>
#include <cstdint>
#include <set>
#include <algorithm>
#include <random>
#include <iomanip>
#include <assert.h>

#define ll long long
#define ld long double
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;

int process_left(int max_diff, vector<int> &a, int start_index, vector<int> &prefix_diffs, vector<int> &postfix_diffs) {
    int max_diff_inside = 0;
    int left_val = a[start_index];
    int right_val = 0;
    for (int i = start_index - 1; i > -1; i--) {
        right_val = a[i];
        max_diff_inside = max(max_diff_inside, 2 * abs(a[i] - a[i + 1]));
        if (i != 0)
            max_diff = min(
                max_diff,
                max({
                        max_diff_inside,
                        prefix_diffs[i - 1],
                        postfix_diffs[start_index + 1],
                        abs(a[i - 1] - 2 * left_val),
                        abs(a[start_index + 1] - 2 * right_val),
                    }
                )
            );
        else
            max_diff = min(
                max_diff,
                max({
                        max_diff_inside,
                        postfix_diffs[start_index + 1],
                        abs(a[start_index + 1] - 2 * right_val),
                    }
                )
            );
    }
    return max_diff;
}

int process_right(int max_diff, vector<int> &a, int start_index, vector<int> &prefix_diffs,
                  vector<int> &postfix_diffs) {
    int max_diff_inside = 0;
    int left_val = 0;
    int right_val = a[start_index];
    for (int i = start_index + 1; i < a.size(); i++) {
        left_val = a[i];
        max_diff_inside = max(max_diff_inside, 2 * abs(a[i] - a[i - 1]));
        if (i != a.size() - 1)
            max_diff = min(
                max_diff,
                max({
                    max_diff_inside,
                    prefix_diffs[start_index - 1],
                    postfix_diffs[i + 1],
                    abs(a[start_index - 1] - 2 * left_val),
                    abs(a[i + 1] - 2 * right_val),
                })
            );
        else
            max_diff = min(
                max_diff,
                max({
                    max_diff_inside,
                    prefix_diffs[start_index - 1],
                    abs(a[start_index - 1] - 2 * left_val),
                })
            );
    }
    return max_diff;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int max_diff = 0;
    vector<int> diffs(n - 1);
    for (int i = 0; i < n - 1; i++) {
        max_diff = max(max_diff, abs(a[i] - a[i + 1]));
        diffs[i] = abs(a[i] - a[i + 1]);
    }

    vector<int> prefix_diffs(n, 0), postfix_diffs(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        prefix_diffs[i + 1] = max(prefix_diffs[i], diffs[i]);
    }

    postfix_diffs[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        postfix_diffs[i] = max(postfix_diffs[i + 1], diffs[i]);
    }

    int best_diff = max_diff;
    int l = -1, r = -1;
    for (int i = 0; i < n - 1; i++) {
        if (abs(a[i] - a[i + 1]) == max_diff) {
            l = i;
            r = i + 1;
            break;
        }
    }

    // проверка простого умножения левого и правого проблемного символа на 2
    if (l != 0)
        best_diff = min(best_diff,
                        max({
                            abs(2 * a[l] - a[l + 1]),
                            abs(2 * a[l] - a[l - 1]),
                            postfix_diffs[l + 1],
                            prefix_diffs[l - 1]
                        }));
    else
        best_diff = min(best_diff,
                        max({
                            abs(2 * a[l] - a[l + 1]),
                            postfix_diffs[l + 1],
                        }));


    if (r != n - 1)
        best_diff = min(best_diff,
                        max({
                            abs(2 * a[r] - a[r + 1]),
                            abs(2 * a[r] - a[r - 1]),
                            postfix_diffs[r + 1],
                            prefix_diffs[r - 1]
                        }));
    else
        best_diff = min(best_diff,
                        max({
                            abs(2 * a[r] - a[r - 1]),
                            prefix_diffs[r - 1],
                        }));


    best_diff = min(best_diff, process_left(max_diff, a, l, prefix_diffs, postfix_diffs));
    best_diff = min(best_diff, process_right(max_diff, a, r, prefix_diffs, postfix_diffs));
    cout << best_diff << '\n';
}

int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
