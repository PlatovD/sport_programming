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

ll cnt_starts_with_1_until_n(ll num) {
    if (num <= 0) return 0;

    ll cnt = 0;
    ll power_of_10 = 1;

    while (power_of_10 <= num / 10) {
        cnt += power_of_10;
        power_of_10 *= 10;
    }

    if (num >= 2 * power_of_10) {
        cnt += power_of_10;
    } else {
        cnt += num - power_of_10 + 1;
    }

    return cnt;
}


void solve() {
    int n, k;
    cin >> n;

    vector<ld> freq(n);
    vector<ld> total_options(n);
    ld left, right;
    for (int i = 0; i < n; i++) {
        cin >> left >> right;
        freq[i] = cnt_starts_with_1_until_n(right) - cnt_starts_with_1_until_n(left - 1);
        total_options[i] = right - left + 1;
    }
    cin >> k;

    vector dp(n + 1, vector<ld>(n + 1, 0));
    dp[0][0] = 1; // вероятности достичь знчение
    for (int heap_number = 0; heap_number < n; heap_number++) {
        // откуда буду брать
        for (int already_1_have = 0; already_1_have < n; already_1_have++) {
            if (dp[heap_number][already_1_have] == 0) continue;
            dp[heap_number + 1][already_1_have + 1] += freq[heap_number] / total_options[heap_number] * dp[heap_number][
                already_1_have];
            dp[heap_number + 1][already_1_have] += (1 - freq[heap_number] / total_options[heap_number]) * dp[
                heap_number][
                already_1_have];
        }
    }

    int need = (n * k + 99) / 100;
    ld total = 0;
    for (int i = need; i <= n; i++) {
        total += dp[n][i];
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
