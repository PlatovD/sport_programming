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


void solve() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int biggest_len = -1;
    int cur_sum = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        cur_sum += a[r];
        while (l <= r && cur_sum > s) {
            cur_sum -= a[l];
            l++;
        }

        if (cur_sum == s) {
            biggest_len = max(r - l + 1, biggest_len);
        }
    }

    if (biggest_len == -1) {
        cout << -1 << '\n';
        return;
    }
    cout << n - biggest_len << '\n';
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
