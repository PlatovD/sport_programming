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
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    vector columns_prefixes(M + 1, vector<ll>(N + 1, 0));
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            columns_prefixes[j][i + 1] = columns_prefixes[j][i] + a[i][j];
        }
    }


    ll best_sum = -INT64_MAX;
    for (int top = 0; top < N; top++) {
        for (int bottom = top + 1; bottom < N + 1; bottom++) {
            ll current_sum = columns_prefixes[0][bottom] - columns_prefixes[0][top];
            best_sum = max(best_sum, current_sum);
            for (int i = 1; i < M; i++) {
                if (current_sum + columns_prefixes[i][bottom] - columns_prefixes[i][top] < columns_prefixes[i][bottom] -
                    columns_prefixes[i][top]) {
                    current_sum = columns_prefixes[i][bottom] - columns_prefixes[i][top];
                } else {
                    current_sum += columns_prefixes[i][bottom] - columns_prefixes[i][top];
                }
                best_sum = max(best_sum, current_sum);
            }
        }
    }

    cout << best_sum << endl;
}
