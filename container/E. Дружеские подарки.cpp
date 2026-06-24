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
#include<set>
#include <cstdint>
#include <set>
#include <algorithm>
#include <random>
#include <iomanip>
#include <assert.h>
#include <unordered_set>

#define ll long long
using namespace std;


// шаблон
int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &el: a) cin >> el;

        vector starts_from(n + 2, vector<bool>(n + 2));
        vector ends_to(n + 2, vector<bool>(n + 2));

        int best_len = 0;
        for (int start_pos = 0; start_pos < n; start_pos++) {
            int current_sum = 0;
            int current_max = 0;
            int current_min = INT32_MAX;

            for (int len = 0; len < n - start_pos; len++) {
                current_sum += a[start_pos + len];
                current_max = max(current_max, a[start_pos + len]);
                current_min = min(current_min, a[start_pos + len]);

                if (len > 0) {
                    if (a[start_pos + len] == a[start_pos + len - 1]) {
                        break;
                    }
                }
                if (current_sum == (current_max + current_min) * (len + 1) / 2 && current_max - current_min == len) {
                    if (starts_from[current_max + 1][len + 1])
                        best_len = max(best_len, len + 1);
                    if (ends_to[current_min - 1][len + 1])
                        best_len = max(best_len, len + 1);
                    starts_from[current_min][len + 1] = true;
                    ends_to[current_max][len + 1] = true;
                }
            }
        }
        cout << best_len << endl;
    }
}
