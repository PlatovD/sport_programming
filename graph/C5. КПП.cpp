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

void dfs_top_sort(int v, vector<int> &top_sort, vector<bool> &visited, vector<vector<int> > &g) {
    visited[v] = true;
    for (int con: g[v]) {
        if (visited[con]) continue;
        visited[con] = true;
        dfs_top_sort(con, top_sort, visited, g);
    }
    top_sort.push_back(v);
}

void dfs_kcc(int v, int current_comp_num, vector<int> &comp, vector<bool> &visited, vector<vector<int> > &g) {
    visited[v] = true;
    comp[v] = current_comp_num;
    for (int con: g[v]) {
        if (visited[con]) continue;
        visited[con] = true;
        comp[con] = current_comp_num;
        dfs_kcc(con, current_comp_num, comp, visited, g);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > g(n), gt(n);

    vector<ll> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    int m;
    cin >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        gt[v].push_back(u);
    }


    vector<int> top_sort;
    vector visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        dfs_top_sort(i, top_sort, visited, g);
    }
    reverse(top_sort.begin(), top_sort.end());

    int current_comp_num = 0;
    vector<int> comp(n);
    vector visited2(n, false);
    for (int v: top_sort) {
        if (visited2[v]) continue;
        dfs_kcc(v, current_comp_num++, comp, visited2, gt);
    }

    vector<ll> min_prices_for_comp(current_comp_num, INT64_MAX);
    vector<ll> repeats_for_comp(current_comp_num);
    for (int i = 0; i < n; i++) {
        if (prices[i] <= min_prices_for_comp[comp[i]]) {
            if (prices[i] == min_prices_for_comp[comp[i]]) repeats_for_comp[comp[i]]++;
            else {
                min_prices_for_comp[comp[i]] = prices[i];
                repeats_for_comp[comp[i]] = 1;
            }
        }
    }

    ll sum = 0;
    for (int i = 0; i < current_comp_num; i++) sum += min_prices_for_comp[i];
    ll ways = repeats_for_comp[0] % MOD;
    for (int i = 1; i < current_comp_num; i++) {
        ways *= repeats_for_comp[i] % MOD;
        ways %= MOD;
    }
    cout << sum << ' ' << ways << '\n';
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
