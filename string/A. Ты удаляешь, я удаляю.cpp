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

    vector<string> strings;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            strings.push_back(s.substr(0, i) + s.substr(i + 1));
        }
    }

    sort(strings.begin(), strings.end());
    s = strings[strings.size() - 1];
    strings.clear();

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            strings.push_back(s.substr(0, i) + s.substr(i + 1));
        }
    }
    sort(strings.begin(), strings.end());
    cout << strings[0] << '\n';
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
