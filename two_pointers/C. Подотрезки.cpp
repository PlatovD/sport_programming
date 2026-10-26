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
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    queue<ll> q;
    for (int i = 0; i <= k; i++) {
        q.push(-1);
    }

    ll cnt = 0;

    ll cur_sum = 0;
    map<ll, ll> rems;
    for (int r = 0; r < n; r++) {
        // добавляю нужный остаток
        ll front = q.front();
        rems[front]++;
        q.pop();

        cur_sum += a[r];
        ll cur_rem = cur_sum % k;
        cnt += rems[cur_rem];
        q.push(cur_rem);
        if (r == k - 1) {
            rems[0] = 1;
        }
    }

    cout << cnt << '\n';
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
