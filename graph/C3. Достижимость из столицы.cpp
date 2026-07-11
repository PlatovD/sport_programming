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
    for (auto con: g[v]) {
        if (visited[con]) continue;
        visited[con] = true;
        dfs_top_sort(con, top_sort, visited, g);
    }
    top_sort.push_back(v);
}

void dfs_kcc(int v, int current_kcc_num, vector<int> &comp, vector<bool> &visited, vector<vector<int> > &g) {
    visited[v] = true;
    comp[v] = current_kcc_num;
    for (auto con: g[v]) {
        if (visited[con]) continue;
        visited[con] = true;
        dfs_kcc(con, current_kcc_num, comp, visited, g);
    }
}

void dfs_available(int v, vector<bool> &available, vector<vector<int> > &g) {
    available[v] = true;
    for (int con: g[v]) {
        if (available[con]) continue;
        available[con] = true;
        dfs_available(con, available, g);
    }
}

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<vector<int> > g(n), gt(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        gt[v].push_back(u);
    }

    vector visited(n, false);
    vector<int> top_sort;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        dfs_top_sort(i, top_sort, visited, g);
    }
    reverse(top_sort.begin(), top_sort.end());

    int current_kcc_num = 0;
    vector<int> comp(n);
    vector visited2(n, false);
    for (auto v: top_sort) {
        if (visited2[v]) continue;
        dfs_kcc(v, current_kcc_num++, comp, visited2, gt);
    }

    vector<vector<int> > compressed(current_kcc_num);
    for (int i = 0; i < n; i++) {
        for (int con: g[i]) {
            if (comp[con] != comp[i]) compressed[comp[i]].push_back(comp[con]);
        }
    }

    vector available(current_kcc_num, false);
    dfs_available(comp[s], available, compressed);
    int new_edges = 0;
    for (int i = 0; i < current_kcc_num; i++) {
        if (available[i]) continue;
        dfs_available(i, available, compressed);
        new_edges++;
    }
    cout << new_edges;
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
