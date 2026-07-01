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


    int N, M;
    cin >> N >> M;
    vector a(N, vector<ll>(M));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == '0') {
                a[i][j] = 0;
            } else a[i][j] = 1;
        }
    }

    vector columns_prefixes(M, vector<ll>(N + 1, 0));
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            columns_prefixes[j][i + 1] = columns_prefixes[j][i] + a[i][j];
        }
    }


    ll best_area = 0;
    for (int top = 0; top < N; top++) {
        for (int bottom = top + 1; bottom < N + 1; bottom++) {
            ll combo_max = 0;
            ll current_combo = 0;
            for (int i = 0; i < M; i++) {
                // проеряю что только из единичек состоит
                if (columns_prefixes[i][bottom] - columns_prefixes[i][top] != bottom - top) {
                    current_combo = 0;
                } else {
                    current_combo++;
                }
                combo_max = max(combo_max, current_combo);
            }
            best_area = max(best_area, (bottom - top) * combo_max);
        }
    }
    cout << best_area << endl;
}
