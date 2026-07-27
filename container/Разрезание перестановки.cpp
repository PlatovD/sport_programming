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
ll MOD_A = 998244353ll;

vector<ll> factorial(1e6 + 1);

void cache_factorial(vector<ll> &f, ll mod) {
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < factorial.size(); i++) {
        f[i] = i * f[i - 1] % mod;
    }
}

void cache_prefix(vector<ll> &prefix,ll cnt_elements_left, ll mod) {
    for (int i = 0; i < prefix.size(); i++) {
    }
}

ll fast_pow(ll num, ll power, ll mod) {
    num %= mod;
    ll res = 1;
    while (power > 0) {
        if (power & 1) res = res * num % mod;
        num = num * num % mod;
        power >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> a[i];

    vector<ll> prefix(1e6 + 1);


    ll total = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 0 || a[i] == n) continue;

        int lower = a[i] - 1;
        int greater = n - a[i];
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
    cache_factorial(factorial, MOD_A);

    while (t--) {
        solve();
    }
}
