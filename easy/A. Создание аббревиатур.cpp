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
    int n, m;
    cin >> n >> m;

    set<char> start_chars;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        start_chars.insert(s[0]);
    }

    bool bad = false;
    for (int i = 0; i < m; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            char cur = tolower(s[j]);
            if (!start_chars.count(cur)) {
                bad = true;
            }
        }
    }
    if (bad) {
        cout << "NO" << '\n';
    } else {
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
