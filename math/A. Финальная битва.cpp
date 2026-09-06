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

    int num;
    int total = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> num;
        mp[num]++;
        total += num;
    }

    int max_repeats_el = -1;
    int max_repeats = -1;
    for (auto &kv: mp) {
        if (kv.second >= max_repeats) {
            max_repeats_el = kv.first;
            max_repeats = kv.second;
        }
    }

    // если остальных позиций хватит, то могу прям все
    if (max_repeats - 1 <= n - max_repeats) {
        cout << total << '\n';
    } else {
        cout << total - max(0, max_repeats_el * (max_repeats - (n - max_repeats + 2))) << '\n';
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
