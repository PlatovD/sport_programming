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

    vector<int> available(26);
    for (int i = 0; i < 26; i++) cin >> available[i];

    int l = 0;
    int best_len = 0;
    for (int r = 0; r < s.size(); r++) {
        available[s[r] - 'a']--;
        while (available[s[r] - 'a'] < 0) {
            available[s[l] - 'a']++;
            l++;
        }
        best_len = max(r - l + 1, best_len);
    }
    cout << best_len << '\n';
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
