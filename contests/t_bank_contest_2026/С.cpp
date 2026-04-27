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
#include<set>
#include <cstdint>
#include <set>
#include <algorithm>
#include <random>
#include <iomanip>
#include <assert.h>

#define ll long long
using namespace std;

ll MOD = 1e9 + 7;

ll fast_pow(ll number, ll power) {
    if (power == 0) {
        return 1;
    }
    if (power == 1) {
        return number;
    }
    if (power % 2 == 0) {
        ll res = fast_pow(number, power / 2) % MOD;
        return res * res % MOD;
    }
    return fast_pow(number, power - 1) % MOD * number % MOD;
}

// шаблон
int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    ll n;
    ll m;
    cin >> n >> m;
    ll res = m * (m - 1) % MOD;
    res *= fast_pow((m - 2) * (m - 2) + (m - 1), n - 1);
    cout << res % MOD << endl;
}
