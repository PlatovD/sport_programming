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
#include <unordered_set>

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

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        ll current = a[i];
        ll another = 1;
        while (another <= current && current * another <= n - 1) {
            ll prev_index = i - current * another;
            ll next_index = current * another + i;
            if (prev_index < 0 && next_index > n - 1) break;
            if (prev_index >= 0 && a[prev_index] == another && current != another) cnt++;
            if (next_index <= n - 1 && a[next_index] == another) cnt++;
            another++;
        }
    }
    cout << cnt << '\n';
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
