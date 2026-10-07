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

void dfs(vector<int> &top_sort, vector<bool> &visited, vector<vector<int> > &g, int v) {
    visited[v] = true;
    for (auto conn: g[v]) {
        if (visited[conn]) continue;
        dfs(top_sort, visited, g, conn);
    }
    top_sort.push_back(v);
}

void solve() {
    int n;
    cin >> n;

    vector g(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--;
        v--;

        if (y > x) {
            g[u].push_back(v);
        } else {
            g[v].push_back(u);
        }
    }

    vector<int> top_sort;
    vector visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        dfs(top_sort, visited, g, i);
    }

    reverse(top_sort.begin(), top_sort.end());
    map<int, int> result;
    for (int i = 0; i < n; i++) {
        result[top_sort[i]] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';
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
