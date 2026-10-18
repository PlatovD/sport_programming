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

vector pre_calc(3, vector(6, 0));

void pre() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            if (i == 0) {
                pre_calc[i][j] = 10 - (j + 1);
            }
            if (i == 1) {
                pre_calc[i][j] = (10 - (j + 1)) * (10 - (j + 2));
            }
            if (i == 2) {
                pre_calc[i][j] = (10 - (j + 1)) * (10 - (j + 2)) * (10 - (j + 3));
            }
        }
    }
}

string build(int cnt_chars, int cnt_digits) {
    string res = "000000000";
    if (cnt_chars == 1) {
        res[0] = 'A';
        res[4] = 'A';
        res[5] = 'A';
    }
    if (cnt_chars == 2) {
        res[0] = 'A';
        res[4] = 'A';
        res[5] = 'B';
    }
    if (cnt_chars == 3) {
        res[0] = 'A';
        res[4] = 'B';
        res[5] = 'C';
    }

    int cnt_repeat = 6 - cnt_digits;
    int current_num = 0;
    for (int i = 0; i < 9; i++) {
        if (i == 0 || i == 4 || i == 5) continue;
        res[i] = to_string(current_num)[0];
        cnt_repeat--;
        if (cnt_repeat < 0) {
            cnt_repeat = 0;
            current_num++;
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    int i_found = -1;
    int j_found = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            if (pre_calc[i][j] == n) {
                i_found = i;
                j_found = j;
                break;
            }
        }
    }

    if (i_found == -1) {
        cout << -1 << '\n';
        return;
    }

    string res = build(i_found + 1, j_found + 1);
    cout << res << '\n';
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
    pre();
    cin >> t;
    while (t--) {
        solve();
    }
}
