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

ll count_divisions(ll x, ll b) {
    ll v = (b - 1) * x + b * b;

    ll cnt = 0;
    while (v % b == 0) {
        cnt++;
        v /= b;
    }
    return cnt;
}


void solve() {
    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> dividers;
    for (ll i = 2; x >= i * i; i++) {
        if (x % i == 0) {
            dividers.push_back(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) dividers.push_back(x);

    ll best_score = 0;
    for (long long divider: dividers) {
        ll current_score = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % divider != 0) continue;
            ll steps = a[i] / divider;
            current_score += steps * divider;
        }
        best_score = max(best_score, current_score);
    }
    cout << best_score << '\n';
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
