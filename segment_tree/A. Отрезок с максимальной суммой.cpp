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

struct node {
    ll seg;
    ll sum;
    ll max_prefix;
    ll max_suffix;
};

struct segtree {
    vector<node> tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size - 1, node());
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = {v, v, v, v};
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }

        node left_node = tree[2 * x + 1];
        node right_node = tree[2 * x + 2];
        tree[x] = {
            max(left_node.seg, max(right_node.seg, left_node.max_suffix + right_node.max_prefix)),
            left_node.sum + right_node.sum,
            max(left_node.max_prefix, left_node.sum + right_node.max_prefix),
            max(right_node.max_suffix, right_node.sum + left_node.max_suffix)
        };
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    ll get() {
        return max(tree[0].seg, 0ll);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        st.set(i, v);
    }

    cout << st.get() << '\n';
    for (int k = 0; k < m; k++) {
        int i, v;
        cin >> i >> v;
        st.set(i, v);
        cout << st.get() << '\n';
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
