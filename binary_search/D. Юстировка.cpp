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

ll sign(ll a) {
    if (a > 0) return 1;
    if (a < 0) return -1;
    return 0;
}

bool check(ll target, vector<ll> &a, vector<ll> &b, vector<ll> &c, ll k) {
    for (int i = 0; i < a.size(); i++) {
        ll cur_sum = a[i] + b[i] + c[i];
        if (cur_sum >= target) continue;

        ll diff = target - cur_sum;
        if (a[i] > b[i] || a[i] > c[i] || b[i] > c[i]) {
            k -= diff;
            if (k < 0) return false;
            continue;
        }

        ll min_to_make_good = INT64_MAX;
        if (a[i] != c[i]) {
            min_to_make_good = min(b[i] - a[i] + 1, min_to_make_good);
        }

        if (a[i] != b[i]) {
            min_to_make_good = min(c[i] - a[i] + 1, min_to_make_good);
        }

        if (a[i] != b[i]) {
            min_to_make_good = min(c[i] - b[i] + 1, min_to_make_good);
        }

        if (min_to_make_good == INT64_MAX) {
            return false;
        }

        k -= diff + 2 * min_to_make_good;
        if (k < 0) return false;
    }

    return k >= 0;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }

    ll max_good = -1e9;
    ll l = -3e18, r = 3e18;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid, a, b, c, k)) {
            max_good = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << max_good << '\n';
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
