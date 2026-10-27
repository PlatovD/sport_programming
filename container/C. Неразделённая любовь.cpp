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

bool good_indexes(int a, int b, int c, int n) {
    if (a >= n || a < 0) return false;
    if (b >= n || b < 0) return false;
    if (c >= n || c < 0) return false;
    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll total = 0;
    map<ll, ll> sum_counts;
    for (int i = 0; i < n; i++) {
        vector<ll> deleted;
        if (!good_indexes(i - 2, i, i + 2, n)) continue;
        ll cur_sum = a[i - 2] + a[i] - a[i + 2];

        if (good_indexes(i - 6, i - 4, i - 2, n)) {
            ll del = a[i - 6] + a[i - 4] - a[i - 2];
            deleted.push_back(del);
            sum_counts[del]--;
        }

        if (good_indexes(i - 4, i - 2, i, n)) {
            ll del = a[i - 4] + a[i - 2] - a[i];
            deleted.push_back(del);
            sum_counts[del]--;
        }

        total += sum_counts[cur_sum];
        for (auto el: deleted) {
            sum_counts[el]++;
        }
        sum_counts[cur_sum]++;
    }

    cout << total << '\n';
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
