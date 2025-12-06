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
#include <memory>
#define _DEBUG

#define ll long long
using namespace std;

class segtree {
public:
    vector<ll> t;
    int n;

    segtree(vector<int> &arr) {
        n = (int) arr.size();
        t.resize(2 * n);
        build(arr, 0, 0, n);
    }

    segtree(const int size) {
        n = size;
        t.resize(2 * size);
    }

    void set(int i, int v) {
        int x = n + i - 1;
        t[x] = v;
        while (x != 0) {
            x = (x - 1) / 2;
            t[x] = t[2 * x + 1] + t[2 * x + 2];
        }
    }

    ll sum(int l, int r) {
        l = l + n - 1;
        r = r + n - 2;
        ll ans = 0;
        while (l <= r) {
            if (l % 2 == 0) ans += t[l];
            l = l / 2;
            if (r % 2 == 1) ans += t[r];
            r = r / 2 - 1;
        }
        return ans;
    }

private:
    void build(vector<int> &arr, int v, int tl, int tr) {
        if (tl == tr - 1) {
            t[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, v * 2 + 1, tl, tm);
            build(arr, v * 2 + 2, tm, tr);
            t[v] = t[v * 2 + 1] + t[v * 2 + 2];
        }
    }
};


int main() {
#if defined _DEBUG
    freopen("rvq.in", "r", stdin);
    freopen("sum.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    auto tree = std::make_unique<segtree>(n);
    char s;
    int v1, v2;
    for (int i = 0; i < k; i++) {
        cin >> s >> v1 >> v2;
        if (s == 'A') {
            tree->set(v1 - 1, v2);
        } else {
            v1--;
            v2--;
            cout << tree->sum(v1, v2 + 1) << '\n';
        }
    }
}

