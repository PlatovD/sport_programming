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
    vector<> tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n)
            size <<= 2;
        tree.resize(2 * size - 1);
    }

    void set(int i, char ch, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[i] = ch;
            return;
        }

        int mid = lx + (rx - lx) / 2;
        if (i < mid) {
            set(i, ch, 2 * x + 1, lx, mid);
        } else {
            set(i, ch, 2 * x + 2, mid, rx);
        }


    }

    void set(int i, char ch) {
        set(i, ch, 0, 0, size);
    }
};

void solve() {
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
