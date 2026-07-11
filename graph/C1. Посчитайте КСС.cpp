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

void dfs_count_kcc(int v, vector<bool> &visited, vector<vector<int> > &g) {
    visited[v] = true;
    for (auto con: g[v]) {
        if (visited[con]) continue;
        visited[con] = true;
        dfs_count_kcc(con, visited, g);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n), gt(n);

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

    vector visited2(n, false);
    int current_kcc = 0;
    for (auto v: top_sort) {
        if (visited2[v]) continue;
        dfs_count_kcc(v, visited2, gt);
        current_kcc++;
    }
    cout << current_kcc  << endl;
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
