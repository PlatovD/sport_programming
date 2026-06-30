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
using namespace std;


ll calc_price_for_k(vector<ll> &a, ll k) {
    ll n = a.size();
    vector<ll> tmp(n);
    for (ll i = 0; i < n; i++) {
        tmp[i] = a[i] + (i + 1) * k;
    }
    sort(tmp.begin(), tmp.end());
    ll total = 0;
    for (ll i = 0; i < k; i++) {
        total += tmp[i];
    }
    return total;
}

// шаблон
int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll l = 0, r = n;
    ll best_cnt_souvenirs = 0;
    ll min_price_for_best_cnt = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll total_min_price_for_k = calc_price_for_k(a, mid);
        if (total_min_price_for_k > s) {
            r = mid - 1;
        } else {
            l = mid + 1;
            best_cnt_souvenirs = mid;
            min_price_for_best_cnt = total_min_price_for_k;
        }
    }
    cout << best_cnt_souvenirs << ' ' << min_price_for_best_cnt << '\n';
}
