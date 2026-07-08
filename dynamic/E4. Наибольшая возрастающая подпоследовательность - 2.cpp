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

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> dp(n, INT64_MAX);
    dp[0] = a[0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i] > dp[j]) {
                dp[j + 1] = min(dp[j + 1], a[i]);
            } else {
                dp[j] = min(dp[j], a[i]);
                break;
            }
        }
    }

    ll best_size = 1;
    for (int i = n - 1; i > -1; i--) {
        if (dp[i] != INT64_MAX) {
            cout << i + 1 << " ";
            best_size = i;
            break;
        }
    }

    vector<ll> pretends(best_size); // претенденты на каждую из позиций, после установления итоговой длины
    ll total = 0;
    for (int i = 0; i < n; i++) {
        ll local_total = 1;
        bool was_match = false;

        if (a[i] == dp[0]) {
            was_match = true;
            pretends[0]++;
            local_total *= 1;
        } else {
            local_total *= dp[0] % MOD;
        }

        if (a[i] == dp[best_size]) {
            was_match = true;
            pretends[best_size]++;
            local_total *= 1;
        } else {
            local_total *= dp[best_size] % MOD;
        }

        for (int j = 1; j < best_size - 1; j++) {
            if (a[])



        }
    }
}
