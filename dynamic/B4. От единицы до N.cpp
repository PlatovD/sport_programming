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

    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> dp(n + 1, 0);
    if (1 + a < n + 1)
        dp[1 + a] += 1;
    if (b < n + 1)
        dp[b] += 1;
    for (int i = 1; i < n + 1; i++) {
        if (dp[i] == 0) continue;

        if (i + a < n + 1)
            dp[i + a] += dp[i];
        if (i * b < n + 1) {
            dp[i * b] += dp[i];
        }
    }
    if (n == 1) cout << 1;
    else cout << dp[n] << endl;
}
