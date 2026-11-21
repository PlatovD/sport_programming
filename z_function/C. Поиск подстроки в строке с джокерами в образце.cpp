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
    string t, p;
    cin >> t >> p;

    int n = t.size();
    int m = p.size();

    vector<int> indexes;
    for (int i = 0; i <= n - m; i++) {
        bool good = true;
        for (int j = i; j < i + m; j++) {
            if (!(p[j - i] == '?' || p[j - i] == t[j])) {
                good = false;
                break;
            }
        }
        if (good) indexes.push_back(i);
    }

    cout << indexes.size() << '\n';
    for (auto x: indexes) cout << x << " ";
    cout << '\n';
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
