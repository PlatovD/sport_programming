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
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll max_diff = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            max_diff = max(max_diff, a[i - 1] - a[i]);
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) a[i] += max_diff;
    }

    bool is_good = true;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            is_good = false;
            break;
        }
    }

    if (is_good) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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
