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

vector grandy(1e6 + 10, -1);

int mex(int a, int b) {
    for (int i = 0; i < 3; i++) {
        if (i == a || i == b) continue;
        return i;
    }
    return 0;
}

int dfs(int num, vector<int> &grandy) {
    if (num == 0) {
        grandy[0] = 0;
        return 0;
    }

    if (grandy[num] != -1) {
        return grandy[num];
    }

    int cur_mex = mex(dfs(num - 1, grandy), dfs(num - num / 2, grandy));
    grandy[num] = cur_mex;
    return cur_mex;
}

void solve() {
    int n;
    cin >> n;

    ll cur_xor = 0;
    ll num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        cur_xor ^= grandy[num];
    }
    if (cur_xor == 0) {
        cout << "Second" << '\n';
    } else {
        cout << "First" << '\n';
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
    cin >> t;

    grandy[0] = 0;
    grandy[1] = 1;
    for (int i = 2; i < 1e6 + 1; i++) {
        if (grandy[i] != -1) continue;
        dfs(i, grandy);
    }


    while (t--) {
        solve();
    }
}
