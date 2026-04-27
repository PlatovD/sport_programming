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
#include<set>
#include <cstdint>
#include <algorithm>
#include <random>
#include <iomanip>
#include <assert.h>

#define ll long long
using namespace std;

int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    ll n, x;
    if (!(cin >> n >> x)) return 0;
    ll a1 = 1;
    vector<pair<ll, int> > coeffs;
    ll temp_k;
    int idx = 1;
    for (int i = 0; i < n; i++) {
        cin >> temp_k;
        coeffs.push_back({temp_k, idx++});
    }

    ll target = x / a1;
    sort(coeffs.rbegin(), coeffs.rend());

    struct Solution {
        ll n, r, k_val;
        int original_idx;
    };
    vector<Solution> results;

    ll sum_n = 0;
    ll sum_r = 0;

    for (auto &p: coeffs) {
        ll k = p.first;
        ll y = (ll) round((double) target / k);
        target -= (y * k);

        Solution sol;
        sol.k_val = k;
        sol.original_idx = p.second;
        if (y >= 0) {
            sol.n = y;
            sol.r = 0;
        } else {
            sol.n = 0;
            sol.r = abs(y);
        }
        sum_n += sol.n;
        sum_r += sol.r;
        results.push_back(sol);
    }

    ll y0 = target;
    ll n0, r0;
    if (y0 >= 0) {
        n0 = y0;
        r0 = 0;
    } else {
        n0 = 0;
        r0 = abs(y0);
    }
    sum_n += n0;
    sum_r += r0;


    cout << sum_n + sum_r << endl;
    return 0;
}
