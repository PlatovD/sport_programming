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

ll next(ll num) {
    vector<ll> digits;
    while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    ll res_num = 0;
    for (auto digit: digits) {
        res_num += digit * digit;
    }
    return res_num;
}

ll check_cycle(ll num, int cnt_operations) {
    while (cnt_operations--) {
        num = next(num);
    }
    return num;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> simulated(n);
    for (int i = 0; i < n; i++) simulated[i] = check_cycle(a[i], 100);

    map<ll, ll> freq;
    for (int i = 0; i < n; i++) {
        freq[simulated[i]]++;
    }

    ll ans = 0;
    for (auto kv: freq) {
        ans += kv.second * (kv.second - 1) / 2;
    }
    cout << ans << '\n';
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
