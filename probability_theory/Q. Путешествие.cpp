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

void dfs(int v, double p, int current_len, int prev, vector<long double> &lens, vector<vector<int> > &g) {
    bool was_continue = false;
    int total_possibilities = 0;
    for (auto conn: g[v]) {
        if (conn != prev) {
            was_continue = true;
            total_possibilities++;
        }
    }
    for (auto conn: g[v]) {
        if (conn != prev) {
            dfs(conn, p / total_possibilities, current_len + 1, v, lens, g);
        }
    }
    if (was_continue) { return; }
    lens.push_back(current_len * p);
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int> > g(n);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<long double> lens;
    dfs(0, 1, 0, -1, lens, g);

    long double sum = 0;
    for (auto num: lens) sum += num;
    cout << sum;
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
