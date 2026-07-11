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

void dfs_kcc(int v, int current_component_num, vector<int> &comp, vector<bool> &visited, vector<vector<int> > &g) {
    visited[v] = true;
    comp[v] = current_component_num;
    for (int con: g[v]) {
        if (visited[con]) continue;
        visited[con] = true;
        comp[con] = current_component_num;
        dfs_kcc(con, current_component_num, comp, visited, g);
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int> > g(n), gt(n);
    int to;
    for (int i = 0; i < n - 1; i++) {
        cin >> to;
        to--;
        g[i].push_back(to);
        gt[to].push_back(i);
    }
    vector<ll> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    prices[n - 1] = 0;

    vector<int> top_sort;
    vector visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        dfs_top_sort(i, top_sort, visited, g);
    }
    reverse(top_sort.begin(), top_sort.end());

    int current_component_num = 0;
    vector visited2(n, false);
    vector comp(n, 0);
    for (int v: top_sort) {
        if (visited2[v]) continue;
        dfs_kcc(v, current_component_num++, comp, visited2, gt);
    }

    vector<vector<int> > compressed_g(current_component_num);
    for (int i = 0; i < n; i++) {
        for (int con: g[i]) {
            if (comp[i] != comp[con]) compressed_g[comp[i]].push_back(comp[con]);
        }
    }
    vector<ll> compressed_prices(current_component_num, INT64_MAX);
    vector<int> min_prices_v(current_component_num);
    for (int i = 0; i < n; i++) {
        if (compressed_prices[comp[i]] > prices[i]) {
            compressed_prices[comp[i]] = prices[i];
            min_prices_v[comp[i]] = i;
        }
    }

    ll total_sum = 0;
    vector<int> from;
    for (int i = 0; i < current_component_num; i++) {
        if (!compressed_g[i].empty()) continue;
        total_sum += compressed_prices[i];
        from.push_back(min_prices_v[i]);
    }

    cout << total_sum << ' ' << from.size() - 1 << '\n';
    for (int num: from) {
        if (num + 1 == n) continue;
        cout << num + 1 << ' ' << n << '\n';
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

    solve();
}
