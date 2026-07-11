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

class Node {
public:
    pair<int, int> pos;
    bool viewed = false;
    vector<Node *> connected;
};

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

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> labyrinth(n);
    map<pair<int, int>, Node *> graph;

    for (int i = 0; i < n; i++) {
        cin >> labyrinth[i];
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == '.') {
                graph[{i, j}] = new Node();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] != '.')continue;
            if (i != 0) {
                if (labyrinth[i - 1][j] == '.')
                    graph[{i, j}]->connected.push_back(graph[{i - 1, j}]);
            }
            if (j != 0) {
                if (labyrinth[i][j - 1] == '.')
                    graph[{i, j}]->connected.push_back(graph[{i, j - 1}]);
            }
            if (i != n - 1) {
                if (labyrinth[i + 1][j] == '.')
                    graph[{i, j}]->connected.push_back(graph[{i + 1, j}]);
            }
            if (j != m - 1) {
                if (labyrinth[i][j + 1] == '.')
                    graph[{i, j}]->connected.push_back(graph[{i, j + 1}]);
            }
        }
    }

    int required_left = (int) graph.size() - k;
    queue<Node *> q;
    q.push(graph.begin()->second);
    while (!q.empty() && required_left > 0) {
        Node *cur = q.front();
        q.pop();
        if (cur->viewed) continue;
        cur->viewed = true;
        required_left--;
        if (required_left == 0) break;
        for (auto con: cur->connected) {
            if (!con->viewed) {
                q.push(con);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == '.') {
                if (!graph[{i, j}]->viewed) {
                    labyrinth[i][j] = 'X';
                }
            }
        }
        cout << labyrinth[i] << '\n';
    }
}
