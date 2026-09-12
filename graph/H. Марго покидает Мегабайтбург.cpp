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

vector<pair<int, int> > updates = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int> > updates_jump = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    int dx, dy, ax, ay;
    cin >> dx >> dy >> ax >> ay;
    dx--;
    dy--;
    ax--;
    ay--;

    vector dist(n, vector(m, INT32_MAX));
    dist[dx][dy] = 0;
    deque<pair<int, int> > q;
    q.push_front({dx, dy});
    while (!q.empty()) {
        pair<int, int> cur_pos = q.front();
        q.pop_front();

        int dist_cur = dist[cur_pos.first][cur_pos.second];
        if (dist_cur > k) continue;

        for (auto u: updates) {
            int new_x = cur_pos.first + u.first;
            int new_y = cur_pos.second + u.second;
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && g[new_x][new_y] != '#') {
                if (dist_cur < dist[new_x][new_y]) {
                    dist[new_x][new_y] = dist_cur;
                    q.push_front({new_x, new_y});
                }
            }
        }

        for (auto u: updates_jump) {
            int new_x = cur_pos.first + u.first;
            int new_y = cur_pos.second + u.second;
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && g[new_x][new_y] != '#') {
                if (dist_cur + 1 < dist[new_x][new_y]) {
                    dist[new_x][new_y] = dist_cur + 1;
                    q.push_back({new_x, new_y});
                }
            }
        }
    }

    if (dist[ax][ay] <= k) {
        cout << "YES";
    } else {
        cout << "NO";
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
