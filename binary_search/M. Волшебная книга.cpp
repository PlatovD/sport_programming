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

ll cnt_page_ends_with(ll to, ll digit) {
    // в каждой десятке по разу встречается число
    ll ans = to / 10;
    if (to % 10 >= digit) ans++;
    if (digit == 0) ans--;
    return ans;
}

void solve() {
    ll n, k, a, b;
    cin >> n >> k >> a >> b;

    ll total = cnt_page_ends_with(n, a) + cnt_page_ends_with(n, b);
    ll l = 1, r = n;
    ll good_page = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll total_until_mid = cnt_page_ends_with(mid - 1, a) + cnt_page_ends_with(mid - 1, b);
        ll diff = total - total_until_mid;
        if (diff == k) {
            good_page = mid;
            // нужно макс
            l = mid + 1;
        } else if (diff < k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << good_page;
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
