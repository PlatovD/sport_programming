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

void generate_all_poss(string cur, string s, vector<string> &possibilities) {
    if (cur.size() == s.size()) {
        possibilities.push_back(cur);
        return;
    }
    char ch = s[cur.size()];
    if (ch != '?') {
        generate_all_poss(cur + ch, s, possibilities);
        return;
    }
    generate_all_poss(cur + '0', s, possibilities);
    generate_all_poss(cur + '1', s, possibilities);
}

int to_index(const string &s) {
    if (s == "00") return 0;
    if (s == "01") return 1;
    if (s == "10") return 2;
    return 3;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector dp(n, vector<ll>(4));
    // 4 состояния - это возможные окончания последовательности на определнном шаге то есть 00 01 10 11

    string prev = s.substr(0, 2);
    if (prev == "??") {
        dp[0][0]++;
        dp[0][1]++;
        dp[0][2]++;
        dp[0][3]++;
    }
    if (prev == "0?") {
        dp[0][0]++;
        dp[0][1]++;
    }
    if (prev == "1?") {
        dp[0][2]++;
        dp[0][3]++;
    }
    if (prev == "?0") {
        dp[0][0]++;
        dp[0][2]++;
    }
    if (prev == "?1") {
        dp[0][1]++;
        dp[0][3]++;
    }
    if (prev == "00") {
        dp[0][0]++;
    }
    if (prev == "01") {
        dp[0][1]++;
    }
    if (prev == "10") {
        dp[0][2]++;
    }
    if (prev == "11") {
        dp[0][3]++;
    }

    for (int i = 2; i < n; i++) {
        // добавляю текущий символ
        vector<string> possibilities;
        generate_all_poss("", s.substr(i - 2, 3), possibilities);
        for (auto pos: possibilities) {
            int sum_left = pos[0] - '0' + pos[1] - '0';
            int sum_right = pos[2] - '0' + pos[1] - '0';
            if (sum_left == sum_right) continue;
            int left = to_index(pos.substr(0, 2));
            int right = to_index(pos.substr(1, 2));
            dp[i - 1][right] = dp[i - 2][left];
        }
    }

    ll sum = 0;
    for (auto res: dp[n - 2]) {
        sum += res;
    }
    cout << sum << '\n';
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
