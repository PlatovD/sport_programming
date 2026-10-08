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

    string s;
    cin >> s;

    if (s[0] == 's') s[0] = '.';
    if (s[n - 1] == 'p') s[n - 1] = '.';

    bool found_s = false;
    bool found_p = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == 's') found_s = true;
        if (s[i] == 'p') found_p = true;
    }
    cout << (found_s && found_p ? "NO" : "YES") << '\n';
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
