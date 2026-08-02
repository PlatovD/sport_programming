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
        tree.resize(2 * size - 1, 0);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }

        int mid = lx + (rx - lx) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else
            set(i, v, 2 * x + 2, mid, rx);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l)
            return 0;

        if (lx >= l && rx <= r)
            return tree[x];

        int mid = lx + (rx - lx) / 2;
        return get(l, r, 2 * x + 1, lx, mid) + get(l, r, 2 * x + 2, mid, rx);
    }

    int get(int l, int r) {
        return get(l, r, 0, 0, size);
    }
};

void solve() {
    int n;
    cin >> n;
    segtree st;
    st.init(n);

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        cout << st.get(num, n) << ' ';
        st.set(num - 1, 1);
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
