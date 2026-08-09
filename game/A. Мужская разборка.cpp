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

vector grandy(1e4 + 1, -1);

int mex(int a, int b, int c) {
    for (int i = 0; i < 4; i++) {
        if (i != a && i != b && i != c) {
            return i;
        }
    }
    return -1;
}

int dfs(int v, vector<int> &grandy) {
    if (v == 0) {
        grandy[0] = 0;
        return 0;
    }

    if (grandy[v] != -1) {
        return grandy[v];
    }

    int first_pos = INT32_MAX, second_pos = INT32_MAX, third_pos = INT32_MAX;
    first_pos = dfs(v - 1, grandy);
    if (v - 5 > -1)
        second_pos = dfs(v - 5, grandy);
    if (v - 13 > -1)
        third_pos = dfs(v - 13, grandy);
    int cur_mex = mex(first_pos, second_pos, third_pos);
    grandy[v] = cur_mex;
    return cur_mex;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        if (grandy[i] != -1)continue;
        dfs(i, grandy);
    }
    if (grandy[n] == 0) {
        cout << 1;
    } else {
        cout << 2;
    }
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
