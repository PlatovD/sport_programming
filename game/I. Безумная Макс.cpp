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

int get_winner(int current_maks_vertex, int current_lukas_vertex, int last_char, bool is_maks_turn,
               vector<vector<pair<int, char> > > &g, vector<vector<vector<vector<int> > > > &dp) {
    if (dp[current_maks_vertex][current_lukas_vertex][last_char][is_maks_turn] != -1) {
        return dp[current_maks_vertex][current_lukas_vertex][last_char][is_maks_turn];
    }
    int current_v = is_maks_turn ? current_maks_vertex : current_lukas_vertex;
    for (auto edge: g[current_v]) {
        int int_char = edge.second - 'a' + 1;
        if (last_char <= int_char) {
            int next_maks_vertex = is_maks_turn ? edge.first : current_maks_vertex;
            int next_lukas_vertex = is_maks_turn ? current_lukas_vertex : edge.first;

            int res = get_winner(next_maks_vertex, next_lukas_vertex, int_char, !is_maks_turn, g, dp);
            if (res == 0) {
                dp[current_maks_vertex][current_lukas_vertex][last_char][is_maks_turn] = 1;
                return 1;
            }
        }
    }
    dp[current_maks_vertex][current_lukas_vertex][last_char][is_maks_turn] = 0;
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, char> > > g(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        char ch;
        cin >> v >> u >> ch;
        u--;
        v--;
        g[v].push_back({u, ch});
    }

    vector dp(n, vector(n, vector(27, vector(2, -1))));
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (get_winner(i, j, 0, true, g, dp) == 1) {
                cout << "A";
            } else {
                cout << "B";
            }
        }
        cout << "\n";
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

    solve();
}
