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
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;


void solve() {
    ll p, q;
    cin >> p >> q;
    ll q_initial = q;


    if (p % q != 0) {
        cout << p << '\n';
        return;
    }

    set<ll> simple_divs_for_q;
    for (int i = 2; i * i <= q; i++) {
        if (q % i == 0) {
            simple_divs_for_q.insert(i);
            while (q % i == 0)
                q /= i;
        }
    }

    if (q > 1) simple_divs_for_q.insert(q);

    ll best = 1;
    for (auto div: simple_divs_for_q) {
        ll cur_p = p;
        while (cur_p > 0 && cur_p % div == 0) {
            cur_p /= div;
            if (cur_p % q_initial != 0) best = max(best, cur_p);
        }
    }
    cout << best << '\n';
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
