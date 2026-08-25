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

void dfs(int cur_depth, int v, vector<vector<int> > &g, vector<int> &depth) {
    depth[v] = cur_depth;
    for (auto conn: g[v]) {
        dfs(cur_depth + 1, conn, g, depth);
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int> > g(n);
    vector<int> parent(n);
    for (int i = 1; i < n; i++) {
        cin >> parent[i];
        g[parent[i] - 1].push_back(i);
    }

    vector<int> depth(n);
    dfs(0, 0, g, depth);


    int m;
    cin >> m;
    vector is_dam(n, false);
    int dam;
    for (int i = 0; i < m; i++) {
        cin >> dam;
        dam--;
        is_dam[dam] = true;
    }

    cout << m - 1 << ' ';
    if (m - 1 == 0) {
        cout << '\n';
        return;
    }

    int min_depth = INT32_MAX, index = -1;
    for (int i = 0; i < n; i++) {
        if (is_dam[i]) {
            if (min_depth > depth[i]) {
                index = i;
                min_depth = depth[i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (is_dam[i]) {
            if (i == index) continue;
            cout << i + 1 << ' ';
        }
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
