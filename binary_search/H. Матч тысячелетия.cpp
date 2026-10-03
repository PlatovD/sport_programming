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

ll cacl_time(ll curr, vector<ll> &s, vector<ll> &p) {
    ll sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += abs(s[i] - p[i] * curr);
    }
    return sum;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;

    vector<ll> s(n), p(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    ll g = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        g = gcd(g, p[i]);
    }

    for (int i = 0; i < n; i++) {
        p[i] /= g;
    }

    ll left = 1;
    ll right = 1e6;

    while (right - left > 2) {
        ll m1 = left + (right - left) / 3;
        ll m2 = right - (right - left) / 3;

        if (cacl_time(m1, s, p) < cacl_time(m2, s, p)) {
            right = m2;
        } else {
            left = m1;
        }
    }

    ll min_time = cacl_time(left, s, p);
    for (ll curr = left + 1; curr <= right; curr++) {
        min_time = min(min_time, cacl_time(curr, s, p));
    }

    cout << min_time << "\n";
}


int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
