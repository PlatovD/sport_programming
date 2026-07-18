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
    int r, s, p;
    cin >> r >> s >> p;

    int n = 100;
    vector prob(n + 1, vector(n + 1, vector<ld>(n + 1, 0)));
    prob[r][s][p] = 1;
    for (int i = 100; i >= 0; i--) {
        for (int j = 100; j >= 0; j--) {
            for (int k = 100; k >= 0; k--) {
                if (prob[i][j][k] == 0) continue;
                ld active_pairs = i * j + j * k + k * i;
                if (active_pairs == 0) continue;
                if (i > 0) prob[i - 1][j][k] += k * i / active_pairs * prob[i][j][k];
                if (j > 0) prob[i][j - 1][k] += i * j / active_pairs * prob[i][j][k];
                if (k > 0) prob[i][j][k - 1] += j * k / active_pairs * prob[i][j][k];
            }
        }
    }

    ld stone = 0;
    for (int i = 100; i > 0; i--) {
        stone += prob[i][0][0];
    }
    cout << stone << ' ';

    ld scissors = 0;
    for (int i = 100; i > 0; i--) {
        scissors += prob[0][i][0];
    }
    cout << scissors << ' ';

    ld paper = 0;
    for (int i = 100; i > 0; i--) {
        paper += prob[0][0][i];
    }
    cout << paper;
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

    solve();
}
