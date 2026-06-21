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
using namespace std;

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

    int n, m;
    cin >> n >> m;
    vector<vector<int> > matrix(n + 1);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        matrix[x].push_back(y);
        matrix[y].push_back(x);
    }

    vector<int> cost(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> cost[i];
    }

    vector visited(n + 1, false);
    long long total_cost = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            int min_cost = INT32_MAX;
            bool has_server = false;

            while (!q.empty()) {
                int v = q.front();
                q.pop();

                if (v == 1) has_server = true;
                if (v != 1) min_cost = min(min_cost, cost[v]);

                for (int to: matrix[v]) {
                    if (!visited[to]) {
                        visited[to] = true;
                        q.push(to);
                    }
                }
            }

            if (!has_server) {
                total_cost += min_cost;
            }
        }
    }

    cout << total_cost << endl;
}
