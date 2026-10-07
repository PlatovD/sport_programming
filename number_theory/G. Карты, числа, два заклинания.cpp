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

ll get_power_of_2_in_num(ll x) {
    ll cnt = 0;
    while (x > 0 && x % 2 == 0) {
        cnt++;
        x /= 2;
    }
    return cnt;
}

ll fast_pow(ll x, ll power) {
    ll res = 1;
    while (power > 0) {
        if (power & 1) res *= x;
        x *= x;
        power >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    string s;
    cin >> s;

    ll sum_odd = 0;
    ll cnt_even = 0;
    ll sum_even = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            sum_odd += a[i];
        } else {
            cnt_even++;
            sum_even += a[i];
        }
    }

    vector<ll> power_of_2_in_num(n, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            power_of_2_in_num[i] = get_power_of_2_in_num(a[i]);
        else
            power_of_2_in_num[i] = get_power_of_2_in_num(a[i] - 1);
    }

    int to_even_pointer = 0;
    vector to_even(n + 1, vector<int>());
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) continue;
        if (power_of_2_in_num[i] > n) continue;
        to_even[power_of_2_in_num[i]].push_back(i);
    }


    bool is_first_sub = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            is_first_sub = false;
            for (int j = 0; j < n; j++) {
                if (a[j] % 2 == 0) continue;
                to_even[to_even_pointer + power_of_2_in_num[j]].push_back(j);
                sum_odd += a[j] - 1;
            }
            cnt_even = 0;
            sum_even = 0;
        }

        if (s[i] == '0') {
            sum_odd = sum_odd / 2;
            to_even_pointer++;
            for (auto index_of_loosing: to_even[to_even_pointer]) {
                ll tmp = a[index_of_loosing] / fast_pow(2, to_even_pointer);
                sum_odd -= tmp;
                if (tmp % 2 == 1) {
                    cnt_even++;
                    sum_even += tmp;
                }
            }
        }

        cout << sum_even + sum_odd << ' ';
    }
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
