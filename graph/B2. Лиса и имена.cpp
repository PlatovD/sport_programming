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

vector<vector<int> > g(26);
vector<int> visited(26);
vector<int> top_sort;

bool dfs(int v) {
    visited[v] = 1;
    for (auto con: g[v]) {
        if (visited[con] == 0) {
            visited[con] = 1;
            if (dfs(con)) return true;
        }
        if (visited[con] == 1)
            return true;
    }
    top_sort.push_back(v);
    visited[v] = 2;
    return false;
}

// шаблон
int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 1; i < n; i++) {
        bool diff = false;
        for (int j = 0; j < min(v[i].size(), v[i - 1].size()); j++) {
            if (v[i - 1][j] != v[i][j]) {
                g[v[i][j] - 'a'].push_back(v[i - 1][j] - 'a');
                diff = true;
                break;
            }
        }
        if (!diff && v[i - 1].size() > v[i].size()) {
            cout << "Impossible";
            return 0;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (visited[i] == 2) continue;
        if (dfs(i)) {
            cout << "Impossible";
            return 0;
        }
    }
    vector<bool> was(26);
    for (int i : top_sort) {
        cout << char(i + 'a');
        was[i] = true;
    }
    for (int i = 0; i < 26; i++) {
        if (!was[i]) cout << char('a' + i);
    }
}
