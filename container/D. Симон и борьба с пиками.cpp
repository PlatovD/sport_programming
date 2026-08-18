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

pair<int, int> max_pair(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first > b.first) {
        return a;
    }
    return b;
}

struct segtree {
    vector<pair<int, int> > tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n)
            size <<= 1;
        tree.resize(2 * size - 1, {-1, -1});
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = {v, i};
            return;
        }

        int mid = lx + (rx - lx) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else
            set(i, v, 2 * x + 2, mid, rx);

        auto left = tree[2 * x + 1];
        auto right = tree[2 * x + 2];

        if (left.first > right.first) tree[x] = left;
        else tree[x] = right;
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    pair<int, int> get(int l, int r, int x, int lx, int rx) {
        if (l <= lx && rx <= r)
            return tree[x];
        if (rx <= l || lx >= r) {
            return {-1, -1};
        }

        int mid = lx + (rx - lx) / 2;
        return max_pair(get(l, r, 2 * x + 1, lx, mid), get(l, r, 2 * x + 2, mid, rx));
    }

    pair<int, int> get(int l, int r) {
        return get(l, r, 0, 0, size);
    }
};

int dfs_max_symbols_save(vector<int> &current, int l, int r, segtree &tree) {
    if (l >= r) return 0;
    if (r - l == 1) return 1;

    // нахожу максимум из ВСЕХ текущих чисел. Запускаю в две стороны - куда я могу этот максимум придвинуть, что я потеряю при придвижении. В итоге на выходе найди максимально возможное число оставшихся символов
    int max_index = tree.get(l, r).second;

    int left_max_elements = dfs_max_symbols_save(current, l, max_index, tree);
    int right_max_elements = dfs_max_symbols_save(current, max_index + 1, r, tree);
    return 1 + max(left_max_elements, right_max_elements);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    segtree tree;
    tree.init(n);
    for (int i = 0; i < n; i++)
        tree.set(i, a[i]);


    if (n == 2) {
        cout << 0 << '\n';
        return;
    }

    if (n == 3) {
        if (a[1] > a[0] && a[1] > a[2]) {
            cout << 1 << '\n';
        } else cout << 0 << '\n';
        return;
    }

    cout << n - dfs_max_symbols_save(a, 0, n, tree) << '\n';
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
    cin >> t;
    while (t--) {
        solve();
    }
}
