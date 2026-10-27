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

int get_sum_of_digits(int a) {
    int sum = 0;
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    set<int> all_indexes;
    for (int i = 0; i < n; i++) all_indexes.insert(i);

    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            auto it = all_indexes.lower_bound(l);
            while (it != all_indexes.end() && *it <= r) {
                a[*it] = get_sum_of_digits(a[*it]);
                if (a[*it] < 10) {
                    it = all_indexes.erase(it);
                } else
                    ++it;
            }
        } else {
            int x;
            cin >> x;
            x--;
            cout << a[x] << '\n';
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
    cin >> t;
    while (t--) {
        solve();
    }
}
