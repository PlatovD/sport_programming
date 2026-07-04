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

    vector<ll> from(n, -1);
    vector<ll> dp(n, INT64_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
            if (dp[i + 1] > dp[i] + abs(h[i + 1] - h[i])) {
                dp[i + 1] = dp[i] + abs(h[i + 1] - h[i]);
                from[i + 1] = i;
            }
        }
        if (i + 2 < n) {
            if (dp[i + 2] > dp[i] + 3 * abs(h[i + 2] - h[i])) {
                dp[i + 2] = dp[i] + 3 * abs(h[i + 2] - h[i]);
                from[i + 2] = i;
            }
        }
    }
    vector<ll> path;
    ll ptr = n - 1;
    while (ptr >= 0) {
        path.push_back(ptr + 1);
        ptr = from[ptr];
    }
    cout << dp[n - 1] << ' ' << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << ' ';
    }
}
