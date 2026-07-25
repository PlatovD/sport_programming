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

bool check(int n, int m, int l, vector<vector<int> > &field) {
    vector dp(n, vector(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) dp[i][j] = field[i][j] < l ? 0 : 1;

    vector combo_before_current_row_element_per_rows(n, vector(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (dp[i][j - 1] == 0)continue;
            combo_before_current_row_element_per_rows[i][j] =
                    combo_before_current_row_element_per_rows[i][j - 1] + 1;
        }
    }

    vector combo_before_current_col_element_per_cols(m, vector(n + 1, 0));
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n + 1; i++) {
            if (dp[i - 1][j] == 0) continue;
            combo_before_current_col_element_per_cols[j][i] = combo_before_current_col_element_per_cols[j][i - 1] + 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i][j] == 0) continue;

            int prev_max_size = dp[i - 1][j - 1];
            int combo_left = combo_before_current_row_element_per_rows[i][j];
            int combo_top = combo_before_current_col_element_per_cols[j][i];

            int minimal_available = min(prev_max_size, min(combo_top, combo_left));
            if (minimal_available == 0)
                dp[i][j] = 1;
            else dp[i][j] = minimal_available + 1;
        }
    }

    int max_reached = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            max_reached = max(max_reached, dp[i][j]);
        }
    }

    return max_reached >= l;
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector field(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> field[i][j];

    int l = 0, r = min(n, m);
    int best = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(n, m, mid, field)) {
            best = max(best, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << best << '\n';
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
    cin >> t;
    while (t--) {
        solve();
    }
}
