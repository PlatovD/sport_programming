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


void solve() {
    ll k, d1, d0;
    cin >> k >> d1 >> d0;

    ll x = d1 * k + d0;
    // пробую билдить не понижая степень
    ll a = d1;
    ll b = x - a * k - a;

    if (b >= 0) {
        cout << "YES" << '\n';
        cout << 2 << " " << a << " " << a << '\n';
        cout << 1 << " " << b << '\n';
        return;
    }

    if (d1 == 1) {
        a = x / 2;
        b = x / 2 + x % 2;
        if (a < k && b < k) {
            cout << "YES" << '\n';
            cout << 1 << " " << a << '\n';
            cout << 1 << " " << b << '\n';
        } else {
            cout << "NO" << '\n';
        }
        return;
    }

    a = d1 - 1;
    b = x - a * k - a;
    if (b < k) {
        cout << "YES" << '\n';
        cout << 2 << " " << a << " " << a << '\n';
        cout << 1 << " " << b << '\n';
        return;
    }

    cout << "NO" << '\n';
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
