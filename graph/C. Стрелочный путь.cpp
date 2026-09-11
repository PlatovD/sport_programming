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

vector<pair<int, int> > steps = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int n, int i, int j, vector<string> &g, vector<vector<bool> > &visited) {
    visited[i][j] = true;
    for (auto s: steps) {
        int next_i = i + s.first;
        int next_j = j + s.second;

        if (next_i >= 0 && next_i < 2 && next_j < n && next_j >= 0) {
            if (g[next_i][next_j] == '<') next_j--;
            else next_j++;
            if (!visited[next_i][next_j])
                dfs(n, next_i, next_j, g, visited);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<string> g(2);
    for (int i = 0; i < 2; i++) cin >> g[i];

    vector visited(2, vector(n, false));
    dfs(n, 0, 0, g, visited);
    if (visited[1][n - 1]) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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
    cin >> t;
    while (t--) {
        solve();
    }
}
