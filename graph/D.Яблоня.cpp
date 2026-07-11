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

ll res(ll first_size,ll second_size) {
    return first_size * second_size;
}

class Node {
public:
    Node(int number) {
        this->number = number;
    }

    int number;
    bool is_viewed = false;
    ll leafs = 0;
    vector<Node *> child;
};

void fill_information(Node *node) {
    if (node->is_viewed) return;
    node->is_viewed = true;

    bool was_child = false;
    for (auto child: node->child) {
        if (!child->is_viewed) {
            fill_information(child);
            was_child = true;
        }
    }
    if (!was_child) {
        node->leafs = 1;
    }
    for (auto child: node->child) {
        node->leafs += child->leafs;
    }
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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Node *> nodes(n);
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
        }

        int p, ch;
        for (int i = 0; i < n - 1; i++) {
            cin >> p >> ch;
            nodes[ch - 1]->child.push_back(nodes[p - 1]);
            nodes[p - 1]->child.push_back(nodes[ch - 1]);
        }
        fill_information(nodes[0]);

        int q;
        cin >> q;
        vector<pair<int, int> > requests(q);
        int x, y;
        for (int i = 0; i < q; i++) {
            cin >> x >> y;
            requests[i] = {x - 1, y - 1};
        }

        for (auto r: requests) {
            Node *first = nodes[r.first];
            Node *second = nodes[r.second];
            cout << res(first->leafs, second->leafs) << '\n';
        }

        for (auto ptr: nodes) {
            delete ptr;
        }
        nodes.clear();
    }
}
