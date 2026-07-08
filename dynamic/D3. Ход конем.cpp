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
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector dp(n, vector<ll>(m));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 2 < n && j + 1 < m) {
                dp[i + 2][j + 1] += dp[i][j];
            }
            if (i + 1 < n && j + 2 < m) {
                dp[i + 1][j + 2] += dp[i][j];
            }
        }
    }
    cout << dp[n - 1][m - 1] << endl;
}
