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


ll fast_pow(ll num, ll power) {
    ll res = 1;
    while (power > 0) {
        if (power & 1)
            res *= num;
        num *= num;
        power >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    ll total = 0;
    for (int i = 1; i <= n; i++) {
        total += fast_pow(2, i);
    }
    cout << total;
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
