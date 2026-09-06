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

    int bad_0_elements = 0, bad_1_elements = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0' && s[i - 1] == '0') bad_0_elements++;
        if (s[i] == '1' && s[i - 1] == '1') bad_1_elements++;
    }

    int diff = abs(bad_0_elements - bad_1_elements);
    char bad_char = bad_0_elements > bad_1_elements ? '0' : '1';
    if (diff <= 1) {
        cout << bad_0_elements + bad_1_elements << '\n';
    }
    if (diff == 2) {
        if (s[0] != bad_char || s[n - 1] != bad_char) cout << bad_0_elements + bad_1_elements + 1 << '\n';
        else cout << -1 << '\n';
    }
    if (diff == 3) {
        if (s[0] != bad_char && s[n - 1] != bad_char) cout << bad_0_elements + bad_1_elements + 2 << '\n';
        else cout << -1 << '\n';
    }
    if (diff > 3) {
        cout << -1 << '\n';
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
