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

    map<int, int> simple_divs;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            simple_divs[i]++;
            n /= i;
        }
    }
    if (n > 1) simple_divs[n]++;

    int cnt_unique = 0;
    int cnt_total = 0;
    for (auto kv: simple_divs) {
        cnt_unique += 1;
        cnt_total += kv.second;
    }

    cout << cnt_unique + (cnt_total - 1) << '\n';
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
