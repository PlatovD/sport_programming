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

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int cnt_0_to_inv = 0;
    int cnt_1_to_inv = 0;
    int helper_0 = 0;
    int helper_1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cnt_0_to_inv += a[i] == 0 ? 1 : 0;
            cnt_1_to_inv += a[i] == 1 ? 1 : 0;
        } else {
            if (a[i] == 1) helper_1++;
            else helper_0++;
        }
    }

    if (cnt_0_to_inv == 0 && cnt_1_to_inv == 0) {
        cout << 0 << '\n';
        return;
    }

    if (cnt_1_to_inv == 0) {
        if (helper_0 && helper_1) {
            cout << 2 << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }

    if (cnt_1_to_inv % 2 == 0) {
        cout << 2 << '\n';
    } else {
        cout << 1 << '\n';
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
