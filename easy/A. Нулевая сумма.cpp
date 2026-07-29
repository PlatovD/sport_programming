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
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n % 2 == 1) {
        cout << "NO" << '\n';
        return;
    }

    int cnt_pos = 0;
    for (int i = 0; i < n; i++) cnt_pos += a[i] > 0 ? 1 : 0;

    int cnt_neg = 0;
    for (int i = 0; i < n; i++) cnt_neg += a[i] < 0 ? 1 : 0;

    int need_pos = n / 2;
    int need_neg = n / 2;
    if (abs(cnt_pos - need_pos) % 2 == 0 && abs(cnt_neg - need_neg) % 2 == 0) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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
