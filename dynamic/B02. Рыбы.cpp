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


void solve() {
    int n;
    cin >> n;

    vector h(n, vector<ld>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> h[i][j];
        }
    }

    vector<ld> dp(1 << n);
    dp[(1 << n) - 1] = 1;

    for (int mask = (1 << n) - 1; mask > 0; mask--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (!(mask & 1 << i)) continue;
                if (!(mask & 1 << j)) continue;

                dp[mask ^ 1 << j] += dp[mask] * h[i][j];
                dp[mask ^ 1 << i] += dp[mask] * h[j][i];
            }
        }
    }

    ld sum = 0;
    for (int i = 1; i < 1 << n; i <<= 1) {
        sum += dp[i];
    }

    for (int i = 1; i < 1 << n; i <<= 1) {
        cout << dp[i] / sum << ' ';
    }
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
