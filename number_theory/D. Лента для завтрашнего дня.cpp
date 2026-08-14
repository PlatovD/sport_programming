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
ll mod = 998244353;

vector<ll> factorial(1e6 + 1, 0);

void precalc_factorial(vector<ll> &factorial, ll mod) {
    factorial[0] = 1;

    for (int i = 1; i <= 1e6; i++)
        factorial[i] = factorial[i - 1] * i % mod;
}

ll fast_pow(ll num, ll power, ll mod) {
    ll res = 1;
    while (power > 0) {
        if (power & 1) res = res * num % mod;
        power >>= 1;
        num = num * num % mod;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    ll cnt0 = 0, cnt1 = 0, seg0 = 0, seg1 = 0;
    char prev = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cnt0++;
            if (prev != s[i]) {
                seg0++;
            }
        } else {
            cnt1++;
            if (prev != s[i]) {
                seg1++;
            }
        }
        prev = s[i];
    }
    ll res0 = 0, res1 = 0;
    if (cnt0 > 0)
        res0 = factorial[cnt0 - 1] * fast_pow(factorial[seg0 - 1], mod - 2, mod) % mod
               * fast_pow(factorial[cnt0 - seg0], mod - 2, mod) % mod;
    if (cnt1 > 0)
        res1 = factorial[cnt1 - 1] * fast_pow(factorial[seg1 - 1], mod - 2, mod) % mod * fast_pow(
                   factorial[cnt1 - seg1], mod - 2, mod) % mod;
    cout << max(1ll, res0 * res1 % mod) << '\n';
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

    precalc_factorial(factorial, mod);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
