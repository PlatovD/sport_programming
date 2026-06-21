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

    ll a, b, c, n;
    cin >> a >> b >> c >> n;
    vector<ll> dp(n + 1, INT64_MAX);
    vector<pair<ll, int> > parent(n + 1, {1, 0});

    dp[1] = 0;

    for (int i = 1; i < n; i++) {
        if (dp[i] == INT64_MAX) continue;

        if (a != 1 && i * a <= n && dp[i * a] > dp[i] + 1) {
            dp[i * a] = dp[i] + 1;
            parent[i * a] = {i, 1};
        }

        if (b != 1 && i * b <= n && dp[i * b] > dp[i] + 1) {
            dp[i * b] = dp[i] + 1;
            parent[i * b] = {i, 2};
        }

        if (c > 0 && i + c <= n && dp[i + c] > dp[i] + 1) {
            dp[i + c] = dp[i] + 1;
            parent[i + c] = {i, 3};
        }
    }

    if (dp[n] == INT64_MAX) {
        cout << -1 << endl;
    } else {
        stack<int> s;
        cout << dp[n] << endl;
        pair<ll, int> p = parent[n];
        while (p.first != 1) {
            s.push(p.second);
            p = parent[p.first];
        }
        if (n !=1)
            s.push(p.second);
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }
}
