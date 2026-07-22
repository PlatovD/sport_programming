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
#define ld long double
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;


void solve() {
    int n, m;
    cin >> n >> m;

    if (m == 1) {
        cout << 1.0;
        return;
    }

    vector<int> get_points(n);
    for (int i = 0; i < n; i++) cin >> get_points[i];

    vector dp(n + 1, vector<double>(n * m + 1, 0));
    vector<double> prefix(n * m + 2, 0);

    dp[0][0] = 1;
    for (int tour = 0; tour < n; tour++) {
        for (int i = 1; i < m * n + 2; i++) {
            prefix[i] = prefix[i - 1] + dp[tour][i - 1];
        }

        for (int points = 0; points <= m * n; points++) {
            // могу прийти из dp[tour][points] + dp[tour][points-1] + dp[tour][points-2] ... dp[tour][points-m+1]
            double numerator = prefix[points] - prefix[max(0, points - m)];
            int busy_index = points - get_points[tour];
            if (busy_index >= 0)
                numerator -= dp[tour][busy_index];
            dp[tour + 1][points] += numerator / (m - 1);
        }
    }

    int cleofas_sum = 0;
    for (int i = 0; i < n; i++) cleofas_sum += get_points[i];

    double p_less = 0;
    for (int points = 0; points < cleofas_sum; points++) {
        p_less += dp[n][points];
    }

    cout << 1.0 + (m - 1) * p_less;;
}

int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
