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

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int cnt_even_a = 0, cnt_odd_a = 0;
    int cnt_even_b = 0, cnt_odd_b = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            cnt_even_a++;
        } else {
            cnt_odd_a++;
        }

        if (b[i] % 2 == 0) {
            cnt_even_b++;
        } else {
            cnt_odd_b++;
        }
    }

    if (k % 2 == 0) {
        if (cnt_even_a > cnt_even_b) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    } else {
        if (cnt_odd_a > cnt_odd_b) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
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
