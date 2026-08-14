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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string game_res(2 * n, '0');
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] != '1') continue;
        if (s[(i + 1) % (2 * n)] == '0') {
            game_res[(i + 1) % (2 * n)] = '1';
        } else {
            game_res[i] = '1';
        }
    }

    int red_team_points = 0, blue_team_points = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (game_res[i - 1] != '1') continue;
        if (i % 2 == 0) {
            red_team_points++;
        } else {
            blue_team_points++;
        }
    }
    cout << red_team_points << ' ' << blue_team_points << '\n';
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
