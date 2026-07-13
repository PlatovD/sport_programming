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

struct Segtree {
    vector<ll> tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size - 1, INT64_MAX);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }

        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    ll min_v(int l, int r, int x, int lx, int rx) {
        if (l >= rx || r <= lx) {
            return INT64_MAX;
        }
        if (lx >= l && rx <= r) {
            return tree[x];
        }

        int m = (lx + rx) / 2;
        ll min_left = min_v(l, r, 2 * x + 1, lx, m);
        ll min_right = min_v(l, r, 2 * x + 2, m, rx);
        return min(min_left, min_right);
    }

    ll min_v(int l, int r) {
        return min_v(l, r, 0, 0, size);
    }
};


void solve() {
    int n, m;
    cin >> n >> m;
    Segtree st;
    st.init(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        st.set(i, v);
    }

    for (int t = 0; t < m; t++) {
        int c;
        cin >> c;
        if (c == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.min_v(l, r) << '\n';
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

    solve();
}
