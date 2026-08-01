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

struct segtree {
    vector<int> tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) {
            size <<= 1;
        }
        tree.resize(2 * size - 1, INT32_MIN);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }

        int m = lx + (rx - lx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }

        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int get(int v, int l, int x, int lx, int rx) {
        if (rx <= l || tree[x] < v) {
            return INT32_MAX;
        }

        // мне не нужно идти туда, где а)индекс меньше l б)значение меньше v
        if (rx - lx == 1) {
            return x - size + 1;
        }

        int m = lx + (rx - lx) / 2;
        int left_val = tree[2 * x + 1];
        int right_val = tree[2 * x + 2];

        int index_left = INT32_MAX, index_right = INT32_MAX;

        if (l < m && left_val >= v) {
            index_left = get(v, l, 2 * x + 1, lx, m);
        }
        if (index_left != INT32_MAX) return index_left;

        if (rx > l && right_val >= v) {
            index_right = get(v, l, 2 * x + 2, m, rx);
        }
        return index_right;
    }

    int get(int v, int l) {
        return get(v, l, 0, 0, size);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    segtree st;
    st.init(n);

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        st.set(i, num);
    }

    while (m--) {
        int operation;
        cin >> operation;
        if (operation == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else {
            int x, l;
            cin >> x >> l;
            int index = st.get(x, l);
            if (index == INT32_MAX || index < l)
                cout << -1 << '\n';
            else
                cout << index << '\n';
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
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
