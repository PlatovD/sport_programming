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
    ll l, r, x;
    cin >> l >> r >> x;

    ll a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << '\n';
        return;
    }

    if (abs(a - b) >= x) {
        cout << 1 << '\n';
        return;
    }

    if (abs(l - b) < x && abs(r - b) < x) {
        cout << -1 << '\n';
        return;
    }

    if (abs(l - a) < x && abs(r - a) < x) {
        cout << -1 << '\n';
        return;
    }

    ll diff_to_l = abs(l - a);
    ll diff_to_r = abs(r - a);
    ll min_actions = INT64_MAX;

    if (diff_to_l >= x) {
        ll pos = l;
        if (abs(pos - b) >= x) min_actions = min(min_actions, 2ll);
        else min_actions = min(min_actions, 3ll);
    }
    if (diff_to_r >= x) {
        ll pos = r;
        if (abs(pos - b) >= x) min_actions = min(min_actions, 2ll);
        else min_actions = min(min_actions, 3ll);
    }

    cout << min_actions << '\n';
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
