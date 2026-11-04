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

void dfs(ll i, vector<vector<ll> > &g, vector<ll> &colors, ll color) {
    colors[i] = color;

    for (ll con: g[i]) {
        if (colors[con] != -1) continue;
        dfs(con, g, colors, color == 1 ? 2 : 1);
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<ll> > g(n);
    int from, to;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;
        from--;
        to--;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    vector colors(n, -1ll);
    dfs(0, g, colors, 1);

    ll cnt_1 = 0;
    ll cnt_2 = 0;
    for (int i = 0; i < n; i++) {
        if (colors[i] == 1) cnt_1++;
        else cnt_2++;
    }

    cout << cnt_1 * cnt_2 - (n - 1);
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
    // cin >> t;
    while (t--) {
        solve();
    }
}
