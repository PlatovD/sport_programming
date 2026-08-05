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

int dfs(int v, int depth, vector<vector<int> > &g, vector<int> &contrib) {
    if (g[v].empty()) return depth;

    if (g[v].size() == 1)
        return dfs(g[v].front(), depth + 1, g, contrib);

    int max_depth_1 = INT32_MIN;
    int max_depth_2 = INT32_MIN;
    for (auto con: g[v]) {
        int step_res = dfs(con, depth + 1, g, contrib);
        if (max_depth_1 <= step_res) {
            max_depth_2 = max_depth_1;
            max_depth_1 = step_res;
        } else if (step_res > max_depth_2)
            max_depth_2 = step_res;
    }
    contrib[v] += max_depth_2 - depth;
    return max_depth_1;
}

void solve() {
    int n;
    cin >> n;

    vector g(n, vector<int>());
    int prev;
    for (int i = 1; i < n; i++) {
        cin >> prev;
        prev--;
        g[prev].push_back(i);
    }

    vector contrib(n, 1);
    dfs(0, 0, g, contrib);
    int ans = 0;
    for (auto num: contrib)
        ans += num;
    cout << ans << '\n';
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
