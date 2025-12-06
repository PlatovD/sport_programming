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
#include <functional>
#include <memory>
#define _DEBUG

#define ll long long
using namespace std;

ll f(int n) {
    return (1LL * n * n) % 12345 + (1LL * n * n * n) % 23456;
}

class SegmentTree {
public:
    vector<pair<ll, ll> > t;
    int size;

    SegmentTree(int n, function<ll(ll)> build_function) {
        size = n;
        t.resize(2 * size, {0, 0});
        build_tree(build_function);
    }

    void set(int i, ll val) {
        i = size + i;
        t[i] = {val, val};
        while (i > 1) {
            i /= 2;
            t[i].first = max(t[i * 2].first, t[i * 2 + 1].first);
            t[i].second = min(t[i * 2].second, t[i * 2 + 1].second);
        }
    }

    pair<ll, ll> get_max_and_min(int l, int r) {
        l = size + l;
        r = size + r;
        ll max_val = INT64_MIN;
        ll min_val = INT64_MAX;
        while (l <= r) {
            if (l % 2 == 1) {
                max_val = max(max_val, t[l].first);
                min_val = min(min_val, t[l].second);
                l++;
            }
            if (r % 2 == 0) {
                max_val = max(max_val, t[r].first);
                min_val = min(min_val, t[r].second);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return {max_val, min_val};
    }

private:
    void build_tree(function<ll(ll)> build_function) {
        for (int i = 0; i < size; i++) {
            t[size + i].first = build_function(i + 1);
            t[size + i].second = build_function(i + 1);
        }
        for (int i = size - 1; i > 0; i--) {
            t[i].first = max(t[2 * i].first, t[2 * i + 1].first);
            t[i].second = min(t[2 * i].second, t[2 * i + 1].second);
        }
    }
};


int main() {
#if defined _DEBUG
    freopen("rvq.in", "r", stdin);
    freopen("rvq.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    int n = 100000;
    auto tree = new SegmentTree(n, f);
    int v1, v2;
    for (int i = 0; i < k; i++) {
        cin >> v1 >> v2;
        if (v1 > 0) {
            pair<ll,ll> res = tree->get_max_and_min(v1 - 1, v2 - 1);
            cout << res.first - res.second << '\n';
        } else {
            tree->set(abs(v1) - 1, v2);
        }
    }
    delete tree;
}
