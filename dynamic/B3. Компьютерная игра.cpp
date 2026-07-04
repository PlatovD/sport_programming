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
    vector<ll> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<ll> dp(n, INT64_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        ll current_h = h[i];
        if (i + 1 < n) {
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(current_h - h[i + 1]));
        }
        if (i + 2 < n) {
            dp[i + 2] = min(dp[i + 2], dp[i] + 3 * abs(current_h - h[i + 2]));
        }
    }

    cout << dp[n - 1] << endl;
}