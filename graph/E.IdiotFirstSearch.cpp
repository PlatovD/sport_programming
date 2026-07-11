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
ll MOD = 1e9 + 7;
using namespace std;

class Node {
public:
    bool is_leaf = false;
    Node *left;
    Node *right;
    Node *parent;
    ll price = 0;
    ll precalculated = -1;
};

void dfs(Node *node) {
    if (node->is_leaf) return;
    dfs(node->left);
    dfs(node->right);
    if (node->left->is_leaf && node->right->is_leaf) {
        node->price = (node->price + 4) % MOD;
    } else {
        node->price = (node->left->price + node->right->price + 4) % MOD;
    }
}

ll calc_price(Node *node) {
    if (node->parent == nullptr) {
        return 0;
    }
    if (node->parent->precalculated != -1) {
        return 1 + node->price + node->parent->precalculated % MOD;
    }
    return (1 + node->price + calc_price(node->parent)) % MOD;
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

        vector<Node *> nodes(n + 1);
        for (int i = 0; i < n + 1; i++) nodes[i] = new Node();
        nodes[1]->parent = nodes[0];
        int l, r;
        for (int i = 1; i < n + 1; i++) {
            cin >> l >> r;
            if (l == 0 && r == 0) {
                nodes[i]->is_leaf = true;
                continue;
            }
            nodes[i]->left = nodes[l];
            nodes[i]->right = nodes[r];
            nodes[l]->parent = nodes[i];
            nodes[r]->parent = nodes[i];
        }

        dfs(nodes[1]);
        vector<ll> results(n);
        for (int i = 1; i < n + 1; i++) {
            results[i - 1] = calc_price(nodes[i]) % MOD;
            nodes[i]->precalculated = results[i - 1];
        }

        for (int i = 0; i < n; i++) {
            cout << results[i] % MOD << ' ';
        }
        cout << '\n';
    }
}
