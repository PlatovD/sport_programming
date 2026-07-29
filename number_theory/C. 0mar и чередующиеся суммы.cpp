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

ll fast_pow(ll num, ll power, ll mod) {
    ll res = 1;

    while (power > 0) {
        if (power & 1) res = (res * num) % mod;
        num = (num * num) % mod;
        power >>= 1;
    }

    return res;
}

void solve() {
    int n;
    cin >> n;

    map<int, int> counts;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        counts[num]++;
    }

    ll total_even = 0;
    for (auto kv: counts) {
        total_even = total_even * fast_pow(2, kv.second - 1, MOD) % MOD;
    }

    ll total_odd = 0;
    for (auto kv: counts) {
        if (kv.first == -1) continue;
        total_odd = total_odd * kv.second % MOD;
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
