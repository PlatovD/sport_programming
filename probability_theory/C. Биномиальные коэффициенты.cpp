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
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;


ll fast_pow(ll num, ll power, ll mod) {
    num %= mod;
    ll res = 1;
    while (power > 0) {
        if (power & 1) {
            res = res * num % mod;
        }
        num = num * num % mod;
        power >>= 1;
    }
    return res;
}

void solve() {
    int m;
    cin >> m;

    vector<ll> factorials(1e6 + 1);

    ll cur = 1;
    int index = 2;
    factorials[0] = 1;
    factorials[1] = cur;
    while (index <= 1e6) {
        cur = cur % MOD * (index % MOD) % MOD;
        factorials[index] = cur;
        index++;
    }

    while (m--) {
        ll n, k;
        cin >> n >> k;
        ll numerator = factorials[n] * fast_pow(factorials[k], MOD - 2, MOD) % MOD;
        ll divider = factorials[n - k];
        cout << numerator * fast_pow(divider, MOD - 2, MOD) % MOD << '\n';
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

    solve();
}
