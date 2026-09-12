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
    ll n, k, s1, s2;
    cin >> n >> k >> s1 >> s2;
    ll min_sum = n;
    ll max_sum = n * k;
    ll mid = min_sum + max_sum;


    bool possible_a = !(s1 < n || s1 > n * k), possible_b = !(s2 < n || s2 > n * k);

    if (n == 1 || s1 == s2 || (!possible_a && !possible_b)) {
        cout << "Equal" << '\n';
        return;
    }

    s1 *= 2;
    s2 *= 2;
    if (abs(s1 - mid) < abs(s2 - mid)) {
        cout << "First" << '\n';
    } else if (abs(s1 - mid) > abs(s2 - mid)) {
        cout << "Second" << '\n';
    } else {
        cout << "Equal" << '\n';
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
    // cin >> t;
    while (t--) {
        solve();
    }
}
