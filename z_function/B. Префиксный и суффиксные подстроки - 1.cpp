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
    string s;
    cin >> s;

    int n = s.size();
    set<string> pref, suff;
    for (int i = 0; i < n; i++) {
        pref.insert(s.substr(0, i + 1));
    }

    for (int i = n - 1; i > -1; i--) {
        suff.insert(s.substr(i, n - i));
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            string cur = s.substr(i, j - i);
            if (pref.count(cur) && suff.count(cur)) {
                continue;
            }
            if (pref.count(cur) || suff.count(cur)) {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
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
