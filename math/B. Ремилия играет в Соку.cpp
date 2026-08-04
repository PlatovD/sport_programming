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
    int n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    x1--;
    x2--;

    if (n <= 3) {
        cout << 1 << '\n';
        return;
    }

    int dist_left, dist_right;
    if (x1 < x2) {
        dist_left = x1 + (n - 1 - x2);
        dist_right = x2 - x1 - 1;
    } else {
        dist_left = x1 - x2 - 1;
        dist_right = (n - 1 - x1) + x2;
    }
    cout << min(dist_left, dist_right) + 1 + k << '\n';
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
