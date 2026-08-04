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
    int n, q;
    cin >> n >> q;

    string s, t;
    cin >> s >> t;

    vector prefix_0_0(n + 1, 0);
    vector prefix_1_1(n + 1, 0);
    vector prefix_0_1(n + 1, 0);
    vector prefix_1_0(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        prefix_0_0[i] = prefix_0_0[i - 1];
        prefix_1_1[i] = prefix_1_1[i - 1];
        prefix_0_1[i] = prefix_0_1[i - 1];
        prefix_1_0[i] = prefix_1_0[i - 1];


        if (s[i - 1] == '0' && t[i - 1] == '0') {
            prefix_0_0[i]++;
        } else if (s[i - 1] == '1' && t[i - 1] == '1') {
            prefix_1_1[i]++;
        } else if (s[i - 1] == '0' && t[i - 1] == '1') {
            prefix_0_1[i]++;
        } else if (s[i - 1] == '1' && t[i - 1] == '0') {
            prefix_1_0[i]++;
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int p0_0 = prefix_0_0[r] - prefix_0_0[l - 1];
        int p1_1 = prefix_1_1[r] - prefix_1_1[l - 1];
        int p0_1 = prefix_0_1[r] - prefix_0_1[l - 1];
        int p1_0 = prefix_1_0[r] - prefix_1_0[l - 1];

        int bad = abs(p0_1 - p1_0);
        bad = max(0, bad - p1_1 - p0_0);
        if (bad > 0)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
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
    while (t--) {
        solve();
    }
}
