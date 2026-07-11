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

void dfs_top_sort(int v, vector<vector<int> > &g, vector<int> &top_sort, vector<bool> &visited) {
    visited[v] = true;
    for (int con: g[v]) {
        if (visited[con]) continue;
        visited[con] = true;
        dfs_top_sort(con, g, top_sort, visited);
    }
    top_sort.push_back(v);
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int> > g(n);
    vector<int> top_sort;
    vector visited(n, false);

    int u, v, x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> x >> y;
        if (x > y) {
            g[--u].push_back(--v);
        } else {
            g[--v].push_back(--u);
        }
    }
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        dfs_top_sort(i, g, top_sort, visited);
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[top_sort[i]] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
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

    int t;
    cin >> t;
    while (t--)
        solve();
}
