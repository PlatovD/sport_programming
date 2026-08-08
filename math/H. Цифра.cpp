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

ll get_count_of_digit_in_number(string num, char digit) {
    ll counter = 0;
    ll factor = 1;
    for (int i = num.length() - 1; i >= 0; i--) {
        if (num[i] >= digit) {
            counter = factor + counter * factor;
        }
        factor *= 10;
    }
    return counter;
}

void solve() {
    string s;
    cin >> s;

    cout << get_count_of_digit_in_number(s, '9');
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
