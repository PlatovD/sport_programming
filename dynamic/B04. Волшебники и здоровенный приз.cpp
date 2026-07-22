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
        int n, l, k;
        cin >> n >> l >> k;
        // n - число туров
        // l - минимальное число побед
        // k - число свободных мест в сумках
        vector<double> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i] /= 100;
        }

        vector<double> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector dp(n + 1, vector(n + 1, vector<double>(401, 0)));
        dp[0][0][200 + k] = 1;
        for (int tour = 0; tour < n; tour++) {
            for (int already_win = 0; already_win <= tour; already_win++) {
                for (int balance = 200 - tour; balance < 401; balance++) {
                    if (dp[tour][already_win][balance] == 0) continue;

                    double win_p = p[tour];
                    int win_balance_change = a[tour];

                    dp[tour + 1][already_win + 1][min(balance + win_balance_change, 400)] +=
                            dp[tour][already_win][balance] * win_p;
                    dp[tour + 1][already_win][balance] += dp[tour][already_win][balance] * (1 - win_p);
                }
            }
        }

        ld total = 0;
        for (int wins = l; wins < n + 1; wins++) {
            for (int balance = 200; balance < 401; balance++) {
                total += dp[n][wins][balance];
            }
        }
        cout << total;
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
