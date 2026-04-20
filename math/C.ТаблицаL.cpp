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


bool can_build(ll x, ll y, ll p, ll q) {
    return p >= abs(x - y);
}

pair<ll, ll> dividers(ll m, ll p, ll q) {
    for (int i = 1; m >= i * i; i++) {
        if (m % i == 0) {
            ll x = (i - 1) / 2;
            ll y = (m / i - 1) / 2;
            if (can_build(x, y, p, q)) {
                return {x, y};
            }
        }
    }
    return {-1, -1};
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

    int t;
    cin >> t;
    while (t--) {
        ll p, q;
        cin >> p >> q;

        ll m = 2 * p + 4 * q + 1;
        auto res = dividers(m, p, q);
        if (res.first == -1) {
            cout << -1 << '\n';
        } else {
            cout << res.first << ' ' << res.second << '\n';
        }
    }
}
