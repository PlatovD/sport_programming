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

int find_pos_for_el(int el, vector<int> &dp) {
    int l = 0, r = dp.size() - 1;
    int good_pos = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (dp[mid] >= el) {
            good_pos = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return good_pos;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector dp(n, 1);
    vector<ll> ways(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                if (dp[i] < 1 + dp[j]) {
                    ways[i] = 1;
                    dp[i] = 1 + dp[j];
                    ways[i] = ways[j];
                } else if (dp[i] == 1 + dp[j]) {
                    ways[i] = (ways[i] + ways[j]) % MOD;
                }
            }
        }
    }

    int max_len = -1;
    for (int i = 0; i < n; i++) {
        max_len = max(max_len, dp[i]);
    }
    cout << max_len << ' ';

    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == max_len) {
            res = (res + ways[i] % MOD) % MOD;
        }
    }
    cout << res;
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
    // cin >> t;
    while (t--) {
        solve();
    }
}
