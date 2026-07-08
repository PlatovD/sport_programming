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

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<ll> dp(n, INT64_MIN);
    for (int i = n - 1; i > -1; i--) {
        dp[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) dp[i] = max(dp[i], b[i] + dp[j]);
        }
    }

    ll best = INT64_MIN;
    for (int i = 0; i < n; i++) {
        best = max(best, dp[i]);
    }
    cout << best;
}
