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
    vector is_deleted(n, false);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    int l = k - 1, r = n - k;
    while (l < n) {
        if (a[l] > a[r]) {
            sum += a[l];
            is_deleted[l] = true;
            if (r < l) r--;
            while (l < n && is_deleted[l]) l++;
            while (r > -1 && is_deleted[r]) r--;
        } else {
            sum += a[r];
            is_deleted[r] = true;
            if (r < l) l++;
            while (r > -1 && is_deleted[r]) r--;
            while (l < n && is_deleted[l]) l++;
        }
    }

    cout << sum << '\n';
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
