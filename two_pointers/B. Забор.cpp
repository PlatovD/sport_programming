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
    ll n, k;
    cin >> n >> k;

    vector<ll> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    ll best_sum_left = -1;
    ll best_sum = INT32_MAX;
    ll cur_sum = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        cur_sum += h[r];
        while (r - l + 1 > k) {
            cur_sum -= h[l];
            l++;
        }
        if (r - l + 1 == k) {
            if (cur_sum < best_sum) {
                best_sum = cur_sum;
                best_sum_left = l;
            }
        }
    }

    cout << best_sum_left + 1;
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
