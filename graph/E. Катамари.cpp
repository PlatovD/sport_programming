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
#include <unordered_set>
#include <variant>

#define ll long long
#define ld long double
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;
vector<pair<int, int> > neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void cnt_neighbors(int i, int j, vector<vector<int> > &g, vector<vector<bool> > &is_center) {
    int n = g.size(), m = g[0].size();
    int cnt_good_neighbors = 0;

    int new_i, new_j;
    for (auto action: neighbors) {
        new_i = i + action.first;
        new_j = j + action.second;

        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
            if (g[new_i][new_j] == g[i][j]) {
                cnt_good_neighbors++;
            }
        }
    }

    if (cnt_good_neighbors == 2) is_center[i][j] = true;
}

void check_can_go_to_next(int i, int j, int next_value, vector<vector<int> > &g,
                          vector<vector<bool> > &can_go_to_next, vector<vector<bool> > &is_center) {
    int n = g.size(), m = g[0].size();

    int new_i, new_j;
    for (auto action: neighbors) {
        new_i = i + action.first;
        new_j = j + action.second;

        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
            if (g[new_i][new_j] == next_value && !is_center[new_i][new_j]) {
                can_go_to_next[i][j] = true;
                break;
            }
        }
    }
}

void try_to_go_through(int i, int j, vector<vector<int> > &g, vector<vector<bool> > &is_center,
                       vector<vector<bool> > &visited, vector<vector<bool> > &can_go_to_next, set<int> &checked,
                       vector<pair<int, int> > &path) {
    path.push_back({i, j});
    int n = g.size(), m = g[0].size();

    visited[i][j] = true;

    int new_i, new_j;
    for (auto action: neighbors) {
        new_i = i + action.first;
        new_j = j + action.second;

        if (!(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m)) continue;
        if (visited[new_i][new_j]) continue;

        // приоритеты выбора
        // 1) такое же значение
        // 2) значение на уровень выше и при этом из новой клетки нельзя в следующую и при этом она не центральная
        // 3) значение на уровень выше и при этом она не центральная
        if (g[new_i][new_j] == g[i][j]) {
            return try_to_go_through(new_i, new_j, g, is_center, visited, can_go_to_next, checked, path);
        }
    }

    auto next = checked.upper_bound(g[i][j]);
    if (next == checked.end()) return;
    int next_val = *next;

    for (auto action: neighbors) {
        new_i = i + action.first;
        new_j = j + action.second;

        if (!(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m)) continue;
        if (visited[new_i][new_j]) continue;

        // приоритеты выбора
        // 1) такое же значение
        // 2) значение на уровень выше и при этом из новой клетки нельзя в следующую и при этом она не центральная
        // 3) значение на уровень выше и при этом она не центральная
        if (g[new_i][new_j] == next_val && !is_center[new_i][new_j] && !can_go_to_next[new_i][new_j]) {
            return try_to_go_through(new_i, new_j, g, is_center, visited, can_go_to_next, checked, path);
        }
    }

    for (auto action: neighbors) {
        new_i = i + action.first;
        new_j = j + action.second;

        if (!(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m)) continue;
        if (visited[new_i][new_j]) continue;

        // приоритеты выбора
        // 1) такое же значение
        // 2) значение на уровень выше и при этом из новой клетки нельзя в следующую и при этом она не центральная
        // 3) значение на уровень выше и при этом она не центральная
        if (g[new_i][new_j] == next_val && !is_center[new_i][new_j]) {
            return try_to_go_through(new_i, new_j, g, is_center, visited, can_go_to_next, checked, path);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector g(n, vector(m, 0));
    set<int> checked;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            checked.insert(g[i][j]);
        }
    }

    // нашел центральные элементы
    vector is_center(n, vector(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt_neighbors(i, j, g, is_center);
        }
    }

    // для каждого случая посчитать переходы
    vector can_go_to_next(n, vector(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto next_value = checked.upper_bound(g[i][j]);
            if (next_value != checked.end())
                check_can_go_to_next(i, j, *next_value, g, can_go_to_next, is_center);
        }
    }

    // нахожу позиции для минимальных элементов
    pair min_pos = {0, 0};
    int cnt_min = 0;
    int min_val = *checked.upper_bound(-1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == min_val) {
                cnt_min++;
                if (!is_center[i][j])
                    min_pos = {i, j};
            }
        }
    }

    vector visited(n, vector(m, false));
    vector<pair<int, int> > path;
    try_to_go_through(min_pos.first, min_pos.second, g, is_center, visited, can_go_to_next, checked, path);

    bool is_bad = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                is_bad = true;
                break;
            }
        }
        if (is_bad) break;
    }

    if (!is_bad) {
        for (auto el: path) {
            cout << el.first + 1 << " " << el.second + 1 << '\n';
        }
        return;
    }

    if (cnt_min < 2) {
        cout << -1;
        return;
    }

    bool was_change = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (min_val == g[i][j] && (min_pos.first != i || min_pos.second != j) && !is_center[i][j]) {
                min_pos.first = i;
                min_pos.second = j;
                was_change = true;
                break;
            }
        }
        if (was_change) break;
    }

    visited.assign(n, vector(m, false));
    path.clear();
    try_to_go_through(min_pos.first, min_pos.second, g, is_center, visited, can_go_to_next, checked, path);

    is_bad = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                is_bad = true;
                break;
            }
        }
        if (is_bad) break;
    }

    if (!is_bad) {
        for (auto el: path) {
            cout << el.first + 1 << " " << el.second + 1 << '\n';
        }
        return;
    }
    cout << -1;
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
