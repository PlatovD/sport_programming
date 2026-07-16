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

ll factorial(ll num) {
    if (num == 1) return 1;
    return (num % MOD * factorial(num - 1) % MOD) % MOD;
}

ll fast_pow(ll num, ll power, ll mod) {
    if (power == 0) return 1;
    if (power == 1) return num;
    if (power % 2 == 0) {
        ll res = fast_pow(num, power / 2, mod) % mod;
        return res * res % mod;
    }
    return num * fast_pow(num, power - 1, mod) % mod;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    ll numerator = factorial(n) % MOD;
    ll denominator = (factorial(k) % MOD * factorial(n - k) % MOD) % MOD;

    ll denominator_inverse = fast_pow(denominator, MOD - 2, MOD) % MOD;
    cout << numerator * denominator_inverse % MOD;
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
