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

struct segtree {
    vector<pair<ll, ll> > tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size - 1, {INT64_MAX, 1});
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = {v, 1};
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }

        pair<ll, ll> left_min = tree[2 * x + 1];
        pair<ll, ll> right_min = tree[2 * x + 2];
        if (left_min.first == right_min.first) {
            tree[x] = {left_min.first, left_min.second + right_min.second};
        } else {
            if (right_min.first < left_min.first) {
                tree[x] = right_min;
            } else {
                tree[x] = left_min;
            }
        }
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    pair<ll,ll> min_v(int l, int r, int x, int lx, int rx) {
        if (l >= rx || r <= lx) {
            return {INT64_MAX, 1};
        }

        if (lx >= l && rx <= r) return tree[x];

        int m = (lx + rx) / 2;
        pair<ll, ll> left_min = min_v(l, r, 2 * x + 1, lx, m);
        pair<ll, ll> right_min = min_v(l, r, 2 * x + 2, m, rx);
        if (left_min.first == right_min.first) {
            return {left_min.first, left_min.second + right_min.second};
        }
        if (left_min.first < right_min.first) {
            return left_min;
        }
        return right_min;
    }

    pair<ll,ll> min_v(int l, int r) {
        return min_v(l, r, 0, 0, size);
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
            pair<ll, ll> ans = st.min_v(l, r);
            cout << ans.first << ' ' << ans.second << '\n';
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
