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
#include <complex>

#define ll long long
#define ld long double
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;

ll fast_pow(ll num, ll power) {
    ll res = 1;
    while (power > 0) {
        if (power & 1) res *= num;
        num *= num;
        power /= 2;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    vector<ll> prefix_sum(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1; i < n + 1; i++) prefix_sum[i] = a[i - 1] + prefix_sum[i - 1];
    unordered_map<ll, ll> counts;
    for (auto x: a) counts[x]++;
    vector<ll> suffixes(m + 2, 0);
    for (int i = m; i > -1; i--) suffixes[i] = suffixes[i + 1] + counts[i];

    for (int k = 1; k <= m; k++) {
        if (k >= 20) {
            cout << prefix_sum[n] << '\n';
            continue;
        }

        ll ans = 0;
        ll p = fast_pow(2, k);
        if (p >= m) {
            cout << prefix_sum[n] << ' ';
            continue;
        }

        for (int x = 1; x <= m / p; x++) {
            int greater = upper_bound(a.begin(), a.end(), p * x) - a.begin();
            ll s = 0;
            for (int i = 1; i < p && i * x <= m; i++) {
                ll right = min((i + 1) * x, m + 1);
                s += i * (suffixes[i * x] - suffixes[right]);
            }

            ll current = counts[p * x] * p + (n - greater) * (p - 1) + s;
            ans = max(ans, current);
        }

        cout << ans << ' ';
    }
    cout << '\n';
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
