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


int mex(set<int> nums) {
    for (int i = 0; i <= nums.size(); i++) {
        if (nums.find(i) != nums.end()) continue;
        return i;
    }
    return 0;
}

int dfs(int v, vector<int> &grandy, vector<vector<int> > &g) {
    if (grandy[v] != -1) return grandy[v];
    set<int> nums;
    for (auto conn: g[v]) {
        nums.insert(dfs(conn, grandy, g));
    }
    grandy[v] = mex(nums);
    return grandy[v];
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector grandy(n, -1);
    vector<vector<int> > g(n);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (grandy[i] != -1) continue;
        dfs(i, grandy, g);
    }


    int k, a;
    cin >> k;

    int cur_xor = 0;
    while (k--) {
        cin >> a;
        a--;
        cur_xor ^= grandy[a];
    }

    if (cur_xor == 0) {
        cout << "second" << '\n';
    } else {
        cout << "first" << '\n';
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
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
