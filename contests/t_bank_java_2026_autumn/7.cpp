#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

#define ll long long

struct DSU {
    vector<int> parent;

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    bool union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            parent[b] = a;
            return true;
        }
        return false;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector dsu(11, DSU(n));

    ll current_mst_weight = 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        current_mst_weight += w;

        for (int k = w; k <= 10; k++) {
            dsu[k].union_sets(u, v);
        }
    }

    while (q--) {
        int u, v, w;
        cin >> u >> v >> w;

        int max_edge = 11;
        for (int k = 1; k <= 10; k++) {
            if (dsu[k].find_set(u) == dsu[k].find_set(v)) {
                max_edge = k;
                break;
            }
        }

        if (max_edge > w) {
            current_mst_weight -= max_edge - w;
            for (int k = w; k <= 10; k++) {
                dsu[k].union_sets(u, v);
            }
        }

        cout << current_mst_weight << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
