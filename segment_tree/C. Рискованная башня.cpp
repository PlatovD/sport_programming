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
#include <unordered_set>

#define ll long long
#define ld long double
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;

struct segtree {
    vector<ll> tree;
    vector<ll> count;

    int n;
    int size;

    void init(int n) {
        this->n = n;
        size = 1;
        while (size < n)
            size <<= 1;
        tree.resize(2 * size - 1, 0);
        count.resize(2 * size - 1, 0);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] += v;
            count[x]++;
            return;
        }

        int mid = lx + (rx - lx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        count[x] = count[2 * x + 1] + count[2 * x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int get(int req_sum, int x, int lx, int rx) {
        if (tree[x] < req_sum) return INT32_MAX;
        if (rx - lx == 1) {
            ll val_in_list = count[x] > 0 ? tree[x] / count[x] : 0;
            if (val_in_list == 0) return INT32_MAX;
            ll need = (req_sum + val_in_list - 1) / val_in_list;
            return min(count[x], need);
        }

        int mid = lx + (rx - lx) / 2;
        ll right_sum = tree[2 * x + 2];
        ll right_cnt = count[2 * x + 2];
        if (right_sum >= req_sum) return get(req_sum, 2 * x + 2, mid, rx);
        return right_cnt + get(req_sum - right_sum, 2 * x + 1, lx, mid);
    }

    int get(int req_sum) {
        return get(req_sum, 0, 0, size);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> stability(n);
    for (int i = 0; i < n; i++) cin >> stability[i];

    unordered_set<int> uniq;

    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            uniq.insert(a[i][j]);
        }
    }

    vector uniq_v(uniq.begin(), uniq.end());
    sort(uniq_v.begin(), uniq_v.end());

    segtree st;
    st.init(uniq.size());

    int min_elements_req = m;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            int index = lower_bound(uniq_v.begin(), uniq_v.end(), a[i][j]) - uniq_v.begin();
            st.set(index, a[i][j]);
        }
        min_elements_req = min(st.get(stability[i]), min_elements_req);
    }
    cout << min_elements_req << '\n';
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
