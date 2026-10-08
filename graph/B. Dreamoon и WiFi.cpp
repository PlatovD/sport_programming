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

int fast_pow(int x, int power) {
    int res = 1;
    while (power > 0) {
        if (power & 1) res *= x;
        x *= x;
        power >>= 1;
    }
    return res;
}

int dfs(int pos_cur, int req_pos, int steps_left) {
    if (steps_left == 0) {
        return pos_cur == req_pos ? 1 : 0;
    }

    return dfs(pos_cur + 1, req_pos, steps_left - 1) + dfs(pos_cur - 1, req_pos, steps_left - 1);
}


void solve() {
    string s1;
    cin >> s1;

    string s2;
    cin >> s2;

    int pos_cur = 0;
    int req_pos = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == '+') {
            req_pos++;
        } else {
            req_pos--;
        }
    }

    int cnt_question = 0;
    for (int i = 0; i < s2.length(); i++) {
        if (s2[i] == '?') {
            cnt_question++;
            continue;
        }
        if (s2[i] == '+') {
            pos_cur++;
        } else {
            pos_cur--;
        }
    }

    double total_possibilities = fast_pow(2, cnt_question);
    double good_possibilities = dfs(pos_cur, req_pos, cnt_question);
    cout << good_possibilities / total_possibilities;
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
