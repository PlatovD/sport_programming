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
#define _DEBUG
using namespace std;

// шаблон
int main() {
#if defined _DEBUG
    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int n = 8;

    vector price(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> price[i][j];
        }
    }

    vector dp(n, vector<ll>(n, INT64_MAX));
    dp[n - 1][0] = 0;
    for (int i = n - 1; i > -1; i--) {
        for (int j = 0; j < n; j++) {
            if (i - 1 > -1) {
                dp[i - 1][j] = min(dp[i - 1][j], dp[i][j] + price[i - 1][j]);
            }
            if (j + 1 < n) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + price[i][j + 1]);
            }
            if (i - 1 > -1 && j + 1 < n) {
                dp[i - 1][j + 1] = min(dp[i - 1][j + 1], dp[i][j] + price[i - 1][j + 1]);
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}
