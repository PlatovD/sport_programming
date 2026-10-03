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
using namespace std;

ll MOD = 1e9 + 7;

ll fast_pow(ll num, ll power, ll mod) {
    ll res = 1;
    while (power > 0) {
        if (power & 1) res = res * num % mod;
        num = num * num % mod;
        power >>= 1;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;

    ll total = fast_pow(2, n, MOD);
    ll sub = 0;

    if (n % 3 == 2) {
        ll k = (n + 1) / 3;
        sub = fast_pow(2, k, MOD);
    }

    cout << (total - sub + MOD) % MOD << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
