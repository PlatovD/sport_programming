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

    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> a[i];

    map<int, pair<ll, ll> > positions;
    for (int i = 0; i < 2 * n; i++) {
        if (positions.find(a[i]) == positions.end()) {
            positions[a[i]] = {i, i};
        } else {
            positions[a[i]] = {positions[a[i]].first, i};
        }
    }

    vector<ll> dp(2 * n + 1, 0);
    vector is_long_step(2 * n, false);
    for (int i = 0; i < 2 * n; i++) {
        pair<ll, ll> p = positions[a[i]];
        if (i == p.second) {
            dp[i + 1] = max(dp[i] + 1, dp[p.first] + (i - p.first + 1) * (i - p.first + 1));
        } else {
            dp[i + 1] = dp[i] + 1;
        }
    }

    ll best = 0;
    for (ll val: dp)
        best = max(best, val);
    cout << best << '\n';
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
