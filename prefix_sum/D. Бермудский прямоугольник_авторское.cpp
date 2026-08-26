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
    ll s, q;
    cin >> s >> q;

    vector<ll> dividers;
    for (ll i = 1; i * i <= s; i++) {
        if (s % i == 0) {
            dividers.push_back(i);
            if (i * i != s)
                dividers.push_back(s / i);
        }
    }

    sort(dividers.begin(), dividers.end());
    vector<ll> pref(dividers.size() + 1);
    pref[0] = 0;
    ll prev_side = 0;
    for (int i = 0; i < dividers.size(); i++) {
        ll cur = (dividers[i] - prev_side) * (s / dividers[i]);
        pref[i + 1] = pref[i] + cur;
        prev_side = dividers[i];
    }

    while (q--) {
        ll x, y;
        cin >> x >> y;

        if (x > s) x = s;
        if (y > s) y = s;
        ll x_upb = std::lower_bound(dividers.begin(), dividers.end(), x) - dividers.begin();
        if (x_upb != dividers.size() && y <= s / dividers[x_upb]) {
            cout << x * y << '\n';
            continue;
        }
        ll ans = 0;
        if (x_upb != dividers.size()) {
            ans = pref[x_upb + 1];
            ans -= (dividers[x_upb] - x) * (s / dividers[x_upb]);
        } else {
            ans = pref.back();
        }
        ll y_upb = lower_bound(dividers.begin(), dividers.end(), y) - dividers.begin();
        if (y_upb != dividers.size()) {
            ll upper_ladder = pref.back() - pref[y_upb + 1];
            ans -= upper_ladder;
            ans -= (dividers[y_upb] - y) * (s / dividers[y_upb]);
        }
        cout << ans << '\n';
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
    cin >> t;
    while (t--) {
        solve();
    }
}
