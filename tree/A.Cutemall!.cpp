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
#include<set>
#include <cstdint>
#include <set>
#include <algorithm>
#include <random>
#include <iomanip>
#include <assert.h>

#define ll long long
using namespace std;

class Node {
public:
    int index;
    set<Node *> connected;
    int connected_cnt = 0;


    Node(int index) {
        this->index = index;
    }

    friend bool operator==(const Node &lhs, const Node &rhs) {
        return lhs.index == rhs.index;
    }
};

class Sum {
public:
    int sum = 0;
};

void dfs(Node *node, Node *prev, Sum *sum) {
    for (Node *con: node->connected) {
        if (con == prev) continue;
        dfs(con, node, sum);
        if (con->connected_cnt % 2 == 0) {
            node->connected_cnt--;
            sum->sum++;
        }
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
    int n;
    cin >> n;
    if (n % 2 != 0) {
        cout << -1 << '\n';
        return 0;
    }
    vector<Node *> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node(i + 1);
    }
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        nodes[u - 1]->connected_cnt++;
        nodes[v - 1]->connected_cnt++;
        nodes[u - 1]->connected.insert(nodes[v - 1]);
        nodes[v - 1]->connected.insert(nodes[u - 1]);
    }
    Sum *res = new Sum();
    dfs(nodes[0], nullptr, res);
    cout << res->sum << '\n';
}
