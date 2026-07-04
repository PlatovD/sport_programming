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
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> dp(n + 6, -INT64_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'w' || dp[i] < 0) continue;
        if (i + 1 < n && s[i + 1] != 'w')
            dp[i + 1] = max(dp[i + 1], dp[i] + (s[i + 1] == '"' ? 1 : 0));
        if (i + 3 < n && s[i + 3] != 'w')
            dp[i + 3] = max(dp[i + 3], dp[i] + (s[i + 3] == '"' ? 1 : 0));
        if (i + 5 < n && s[i + 5] != 'w')
            dp[i + 5] = max(dp[i + 5], dp[i] + (s[i + 5] == '"' ? 1 : 0));
    }
    cout << (dp[n - 1] < 0 ? -1 : dp[n - 1]) << endl;
}
