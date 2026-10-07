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

ll res_for_cur(ll x) {
    vector<ll> digits;
    ll copy_x = x;
    while (copy_x > 0) {
        ll cur = copy_x % 10;
        if (cur == 1) return -1;
        digits.push_back(cur);
        copy_x /= 10;
    }
    reverse(digits.begin(), digits.end());
    ll res = x;
    for (auto d: digits) {
        res *= d;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> nums(4000 + 1, -1);
    for (ll i = 0; i < 4001; i++) {
        nums[i] = res_for_cur(i);
    }

    int cnt_ans = 0;
    int ans = -1;
    for (int i = 0; i <= 4000; i++) {
        if (nums[i] == n) {
            cnt_ans++;
            ans = i;
        }
    }
    if (cnt_ans == 1) {
        cout << ans;
        return;
    }
    cout << "ERROR";
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
