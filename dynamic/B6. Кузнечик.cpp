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

ll MOD = 1e9 + 7;

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

    int n, k;
    cin >> n >> k;

    vector<ll> dp(n);
    dp[0] = 1;

    vector<ll> prefix(n + 1);
    prefix[0] = 1;
    for (int i = 1; i < n; i++) {
        if (i - k - 1 > -1)
            dp[i] = (prefix[i - 1] - prefix[i - k - 1] + MOD) % MOD;
        else
            dp[i] = prefix[i - 1] % MOD;
        prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
    }

    cout << dp[n - 1] << endl;
}
