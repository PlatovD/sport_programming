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
    int n;
    cin >> n;

    vector<ll> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    ll max_sum = 0;
    ll left_sum = 0, right_sum = 0;
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        if (left_sum < right_sum) {
            left_sum += d[l];
            l++;
        } else if (right_sum < left_sum) {
            right_sum += d[r];
            r--;
        } else {
            max_sum = left_sum;
            left_sum += d[l];
            l++;
        }
    }
    if (left_sum == right_sum) max_sum = max(left_sum, max_sum);
    cout << max_sum;
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
