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

    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];

    if (n == 1) {
        cout << 1 << ' ' << 0;
        return;
    }

    int a_ate = 1, b_ate = 1;
    int l = 0, r = n - 1;
    while (l < r) {
        int cur_diff = min(t[l], t[r]);
        t[l] -= cur_diff;
        t[r] -= cur_diff;

        if (t[l] == 0) {
            l++;
            if (l < r) a_ate++;
        }

        if (t[r] == 0) {
            r--;
            if (l < r) b_ate++;
        }
    }

    cout << a_ate << ' ' << b_ate;
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
