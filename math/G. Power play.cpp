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

ll fast_pow(ll num, ll power) {
    ll res = 1;
    while (power > 0) {
        if (power & 1) res *= num;
        num *= num;
        power >>= 1;
    }
    return res;
}

void solve() {
    ll a, b;
    cin >> a >> b;

    ll tmp_a = a;
    map<ll, ll> dividers_of_a;
    for (int i = 2; i * i <= tmp_a; i++) {
        while (tmp_a % i == 0) {
            dividers_of_a[i]++;
            tmp_a /= i;
        }
    }
    if (tmp_a > 1) dividers_of_a[tmp_a]++;

    bool good = true;
    ll last_cnt = -1;
    for (auto kv: dividers_of_a) {
        if (last_cnt == -1) {
            last_cnt = kv.second;
            continue;
        }
        if (last_cnt != kv.second) {
            good = false;
            break;
        }
    }

    ll d = 1;
    if (good) {
        for (auto kv: dividers_of_a) {
            if (kv.second > 1) {
                d *= fast_pow(kv.first, kv.second - 1);
            }
        }
    }

    ll c = 1;
    while (true) {
        ll x = fast_pow(a, c);
        if (x < 0 || x > 1e18) {
            break;
        }
        if (x == b * c) {
            cout << x;
            return;
        }
        c++;
    }
    cout << 0;
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
