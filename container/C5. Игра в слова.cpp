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
    int n;
    cin >> n;
    vector<string> v1(n), v2(n), v3(n);
    for (int i = 0; i < n; i++) cin >> v1[i];
    for (int i = 0; i < n; i++) cin >> v2[i];
    for (int i = 0; i < n; i++) cin >> v3[i];

    map<string, int> counts;
    for (int i = 0; i < n; i++) {
        counts[v1[i]]++;
        counts[v2[i]]++;
        counts[v3[i]]++;
    }

    int score_1 = 0, score_2 = 0, score_3 = 0;
    for (int i = 0; i < n; i++) {
        if (counts[v1[i]] == 1) {
            score_1 += 3;
        } else if (counts[v1[i]] == 2) {
            score_1 += 1;
        }

        if (counts[v2[i]] == 1) {
            score_2 += 3;
        } else if (counts[v2[i]] == 2) {
            score_2 += 1;
        }

        if (counts[v3[i]] == 1) {
            score_3 += 3;
        } else if (counts[v3[i]] == 2) {
            score_3 += 1;
        }
    }
    cout << score_1 << " " << score_2 << " " << score_3 << '\n';
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
