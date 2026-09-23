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

    vector<int> cnt_0_before(n + 1);
    cnt_0_before[0] = 0;
    for (int i = 1; i <= n; i++)
        cnt_0_before[i] = cnt_0_before[i - 1] + (s[i - 1] == '0' ? 1 : 0);

    // итерируюсь по количеству 0
    int min_operations = INT32_MAX;
    for (int i = 0; i <= n; i++) {
        int total_replacements = 0;

        int cnt_0 = i;
        int cnt_1 = n - i;
        if (cnt_0 > 0) {
            if (s[0] != '0') continue;
            total_replacements += i - cnt_0_before[i];
        }
        if (cnt_1 > 0) {
            if (s[i] != '1') continue;
            total_replacements += cnt_0_before[n] - cnt_0_before[i];
        }
        min_operations = min(total_replacements, min_operations);
    }

    cout << min_operations << '\n';
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
