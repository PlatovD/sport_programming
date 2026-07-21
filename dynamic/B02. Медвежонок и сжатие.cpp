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

void generate_all(string cur, int left, vector<string> &comb) {
    if (left == 0) {
        comb.push_back(cur);
        return;
    }
    vector chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    for (auto ch: chars) {
        generate_all(cur + ch, left - 1, comb);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<map<string, ll> > dp(n);
    map<string, char> m;
    string s1, s2;
    while (q--) {
        cin >> s1 >> s2;
        m[s1] = s2[0];
    }

    vector<string> comb;
    generate_all("", n, comb);
    for (auto s: comb) {
        dp[n - 1][s]++;
    }

    for (int i = n - 1; i > 0; i--) {
        for (auto s: dp[i]) {
            for (auto start: m) {
                if (s.second == 0) continue;
                if (s.first[0] == start.first[0] && s.first[1] == start.first[1]) {
                    dp[i - 1][start.second + s.first.substr(2)] += s.second;
                }
            }
        }
    }

    cout << dp[0]["a"];
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
