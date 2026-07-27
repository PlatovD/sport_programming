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

    int left_1 = n / 2;
    int left_0 = n / 2 + n % 2;

    string res;
    res.resize(10);

    vector<string> blocks(n - k);
    for (int i = 0; i < n - k; i++) {
        if (i % 2 == 0) {
            blocks[i] += '0';
            left_0--;
        } else {
            blocks[i] += '1';
            left_1--;
        }
    }

    if (left_0 < 0 || left_1 < 0) {
        cout << -1 << '\n';
        return;
    }

    while (left_0 > 0) {
        blocks[0] += '0';
        left_0--;
    }

    if (left_1 > 0 && blocks.size() == 1) {
        cout << -1 << '\n';
        return;
    }

    while (left_1 > 0) {
        blocks[1] += '1';
        left_1--;
    }

    for (const auto &el: blocks) {
        cout << el;
    }
    cout << '\n';
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
