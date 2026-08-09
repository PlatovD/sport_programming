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

bool dfs(int v, vector<vector<pair<int, int> > > &g, vector<int> &party_nums, int req_color) {
    if (party_nums[v] != 0 && party_nums[v] != req_color) {
        return true;
    }

    if (party_nums[v] == req_color) {
        return false;
    }

    party_nums[v] = req_color;
    for (auto conn: g[v]) {
        // друг
        if (conn.second == 1) {
            if (dfs(conn.first, g, party_nums, req_color)) {
                return true;
            }
        } else {
            if (dfs(conn.first, g, party_nums, req_color == 1 ? 2 : 1)) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector g(n, vector<pair<int, int> >());
    vector party_nums(n, 0);
    while (m--) {
        int x, y, t;
        cin >> x >> y >> t;
        x--;
        y--;
        g[x].push_back({y, t});
        g[y].push_back({x, t});
    }

    bool bad = false;
    for (int i = 0; i < n; i++) {
        if (party_nums[i] != 0) continue;
        if (dfs(i, g, party_nums, 1)) {
            bad = true;
            break;
        }
    }
    if (bad) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (auto num: party_nums) cout << num << ' ';
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
