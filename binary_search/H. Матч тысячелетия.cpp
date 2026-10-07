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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll check(ll k, vector<ll> &s, vector<ll> &p) {
    ll total = 0;
    for (int i = 0; i < s.size(); i++) {
        total += abs(k * p[i] - s[i]);
    }
    return total;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> s(n), p(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> p[i];

    ll g = 0;
    for (int i = 0; i < n; i++) {
        g = gcd(g, p[i]);
    }

    for (int i = 0; i < n; i++) {
        p[i] /= g;
    }

    ll left = 1;
    ll right = 1e12;
    while (left < right) {
        ll mid = left + (right - left) / 2;
        ll m1 = check(mid, s, p);
        ll m2 = check(mid + 1, s, p);
        if (m1 < m2) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << check(left, s, p);
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
