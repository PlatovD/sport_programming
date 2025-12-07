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

#define ll long long
using namespace std;

class SegmentTree {
public:
    vector<ll> t;
    int size;

    SegmentTree(int n) {
        size = n;
        t.resize(size * 2, 0);
    }

    void set(int i, ll val) {
        i += size;
        t[i] = val;
        while (i > 1) {
            i /= 2;
            t[i] = t[2 * i] + t[2 * i + 1];
        }
    }

    /**
     * @param l left border included
     * @param r right border included
     * @return value
     */
    ll get(int l, int r) {
        l += size;
        r += size;
        ll sum = 0;
        while (l <= r) {
            if (l % 2 == 1) {
                sum += t[l];
                l++;
            }
            if (r % 2 == 0) {
                sum += t[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }
};


int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int n;
        cin >> n;
        auto tree = SegmentTree(n);
        ll res = 0;
        ll num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            if (num >= i + 1) {
                continue;
            }
            res += tree.get(0, num - 2);
            tree.set(i, 1);
        }
        cout << res << '\n';
    }
}
