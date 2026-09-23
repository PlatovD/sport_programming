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

    set<int> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.insert(a - i); // эта разность постоянна для числа на каждой позиции
    }

    int best_len = 0;
    int current_len = 0;
    int last_val = INT32_MIN;
    for (auto x: s) {
        if (x != last_val + 1) {
            best_len = max(best_len, current_len);
            current_len = 0;
        }
        current_len++;
        last_val = x;
    }
    best_len = max(best_len, current_len);
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
    cin >> t;
    while (t--) {
        solve();
    }
}
