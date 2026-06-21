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

bool can_reach_k(vector<ll> &v, ll k, ll x) {
    ll max_total = 0;
    for (auto num: v) {
        max_total += min(num, x);
    }
    return max_total >= k;
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

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    ll l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        r = max(v[i], r);
    }

    ll best_try = -1;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (can_reach_k(v, k, m)) {
            best_try = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << best_try << endl;
}
