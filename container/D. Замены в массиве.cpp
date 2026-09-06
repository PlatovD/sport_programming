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
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> diff(n - 1);
    for (int i = 0; i < n - 1; i++) diff[i] = a[i + 1] - a[i];

    for (int i = 0; i < n - 1; i++) {
        int j = i;
        while (j < n - 1 && abs(diff[j] % 2) == abs(diff[i] % 2)) j++;
        sort(diff.begin() + i, diff.begin() + j);
        i = j - 1;
    }

    vector<ll> ans(n);
    ans[0] = a[0];
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] + diff[i - 1];
    }
    for (auto x: ans) cout << x << ' ';
    cout << '\n';
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
