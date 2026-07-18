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
        if (power & 1)
            res = res * num % mod;
        num = num * num % mod;
        power >>= 1;
    }
    return res;
}

ll factorial(ll num, ll mod) {
    if (num == 0) return 1;
    if (num == 1) return 1;
    return num % mod * factorial(num - 1, mod) % mod % mod;
}

void solve() {
    ll n;
    cin >> n;

    ll numerator = factorial(2 * n - 1, MOD) % MOD;
    ll divider = fast_pow((factorial(n - 1, MOD) * factorial(n, MOD)) % MOD, MOD - 2, MOD) % MOD;
    ll res = ((2 * numerator % MOD * divider % MOD) % MOD - n + MOD) % MOD;
    cout << res << '\n';
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
