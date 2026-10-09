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

void change_elements(vector<int> &perm, int from, int to) {
    int l = from;
    int r = from + (to - from) / 2;
    while (r < to) {
        swap(perm[l], perm[r]);
        l++;
        r++;
    }
}

int sort_tree(vector<int> &perm, int from, int to) {
    if (to - from == 1) return 0;

    int cnt_until_mid = (to - from) / 2;
    int in_right_part = from + cnt_until_mid + 1;
    int steps = 0;
    for (int i = from; i < from + cnt_until_mid; i++) {
        if (perm[i] >= in_right_part) {
            change_elements(perm, from, to);
            steps++;
            break;
        }
    }
    return steps + sort_tree(perm, from, from + cnt_until_mid) + sort_tree(perm, from + cnt_until_mid, to);
}

void solve() {
    int m;
    cin >> m;

    vector<int> perm(m);
    for (int i = 0; i < m; i++) cin >> perm[i];

    int steps = sort_tree(perm, 0, m);
    bool success = true;
    for (int i = 1; i < m; i++) {
        if (perm[i - 1] > perm[i]) {
            success = false;
            break;
        }
    }

    if (!success) {
        cout << -1 << '\n';
        return;
    }
    cout << steps << '\n';
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
