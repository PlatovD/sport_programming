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
// #define _DEBUG
using namespace std;

// шаблон
int main() {
#if defined _DEBUG
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector steps(n + 5, 0);

    for (int i = 1; i < n + 1; i++) cin >> steps[i];

    vector<ll> dp(n + 5, -INT64_MAX);
    dp[0] = 0;
    for (int i = 0; i < n + 1; i++) {
        dp[i + 1] = max(dp[i + 1], dp[i] + steps[i + 1]);
        dp[i + 2] = max(dp[i + 2], dp[i] + steps[i + 2]);
    }
    cout << dp[n] << endl;
}
