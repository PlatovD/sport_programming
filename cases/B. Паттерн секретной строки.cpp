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

    cout << '?' << ' ' << 1 << ' ' << n << '\n';
    cout.flush();

    int cnt_1_all;
    cin >> cnt_1_all;

    if (cnt_1_all == 0 || cnt_1_all == n) {
        cout << '!' << ' ' << "NO" << '\n';
        cout.flush();
        return;
    }

    cout << '?' << ' ' << 1 << ' ' << cnt_1_all << '\n';
    cout.flush();

    int cnt_1_prefix;
    cin >> cnt_1_prefix;

    if (cnt_1_prefix == cnt_1_all) {
        cout << '!' << ' ' << "NO" << '\n';
        cout.flush();
        return;
    }

    cout << '!' << ' ' << "YES" << '\n';
    cout.flush();
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
