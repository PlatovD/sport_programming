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
    ll c;
    cin >> c;

    ll l = 1, r = 2e9;
    ll best_n = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (mid * (mid - 1) / 2 > c) {
            r = mid - 1;
        } else {
            best_n = max(best_n, mid);
            l = mid + 1;
        }
    }


    if (best_n < 4) {
        cout << 0 << '\n';
        return;
    }
    cout << best_n * (best_n - 1) / 2 << '\n';
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
