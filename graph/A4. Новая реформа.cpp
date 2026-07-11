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
    bool viewed;
    vector<Node *> children;
};

bool has_cycle(Node *cur, Node *prev) {
    cur->viewed = true;
    bool res = false;
    for (auto child: cur->children) {
        if (child->viewed && child != prev) return true;
        if (child != prev) res |= has_cycle(child, cur);
    }
    return res;
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

    int n, m;
    cin >> n >> m;
    vector<Node *> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node();
    }

    int from, to;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        from--;
        to--;

        nodes[from]->children.push_back(nodes[to]);
        nodes[to]->children.push_back(nodes[from]);
    }

    int cnt = 0;
    for (auto node: nodes) {
        if (node->viewed) continue;
        if (!has_cycle(node, nullptr)) {
            cnt++;
        }
    }
    cout << cnt << endl;
}
