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
ll mod = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> prefix_possible_positions(n + 1), suffix_possible_positions(n + 1);
    prefix_possible_positions[0] = 1;
    suffix_possible_positions[n - 1] = 1;
    for (ll i = 1; i < n + 1; i++)
        prefix_possible_positions[i] = prefix_possible_positions[i - 1] * (n - i) % mod;
    for (ll i = n - 2; i > -1; i--)
        suffix_possible_positions[i] = suffix_possible_positions[i + 1] * (n - i - 1) % mod;

    vector<ll> suffix_a(n + 1);
    suffix_a[n] = 0;
    for (ll i = n - 1; i > -1; i--) suffix_a[i] = (suffix_a[i + 1] + a[i]) % mod;

    ll ans = 0;
    for (ll i = 0; i < n - 1; i++) {
        ll Wi = prefix_possible_positions[i] * suffix_possible_positions[i + 1] % mod;
        ll inner = (suffix_a[i + 1] - (n - i - 1) % mod * (a[i] % mod) % mod + mod) % mod;
        ans = (ans + Wi * inner) % mod;
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
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
