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

int max_power(int n, ll max_sum_allowed, int i, int r, vector<ll> &prefix) {
    int best_good_power = -1;
    int l = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (prefix[min(n, i + mid + 1)] - prefix[max(0, i - mid)] <= max_sum_allowed) {
            best_good_power = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return best_good_power;
}

void solve() {
    ll n, r;
    cin >> n >> r;

    vector<ll> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + s[i - 1];

    vector<ll> powers(n, 0);
    for (int i = 0; i < n; i++) {
        powers[i] = max_power(n, r, i, max(i, (int) n - 1 - i), prefix);
    }
    for (auto el: powers) cout << el << '\n';
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
