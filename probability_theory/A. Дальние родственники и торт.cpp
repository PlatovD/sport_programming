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
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;


void solve() {
    int n;
    cin >> n;
    vector<string> map(n);
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    vector rows(n, 0ll);
    vector cols(n, 0ll);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rows[i] += map[i][j] == 'C' ? 1 : 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cols[j] += map[i][j] == 'C' ? 1 : 0;
        }
    }

    ll total = 0;
    for (auto x: rows) {
        total += (x - 1) * x / 2;
    }
    for (auto x: cols) {
        total += (x - 1) * x / 2;
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

    solve();
}
