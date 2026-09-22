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


void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    priority_queue<ll> pq;
    ll sum = 0;
    for (int i = 0; i < m - 1; i++) {
        sum -= a[i];
        pq.push(a[i]);
    }

    ll best_res = INT64_MIN;
    for (int i = m - 1; i < n; i++) {
        best_res = max(best_res, m * a[i] + sum);
        if (pq.empty()) continue;
        ll top = pq.top();
        if (top < a[i]) continue;
        sum += top;
        pq.pop();
        pq.push(a[i]);
        sum -= a[i];
    }

    cout << best_res << '\n';
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
