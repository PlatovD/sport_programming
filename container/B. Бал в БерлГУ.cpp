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

    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a[num]++;
    }

    int m;
    cin >> m;

    map<int, int> b;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        b[num]++;
    }

    int total = 0;
    for (auto x: a) {
        int skill = x.first;

        int first_try = min(x.second, b[skill - 1]);
        total += first_try;
        x.second -= first_try;
        b[skill - 1] -= first_try;

        if (x.second == 0) continue;

        int second_try = min(x.second, b[skill]);
        total += second_try;
        x.second -= second_try;
        b[skill] -= second_try;

        if (x.second == 0) continue;

        int third_try = min(x.second, b[skill + 1]);
        total += third_try;
        x.second -= third_try;
        b[skill + 1] -= third_try;
    }

    cout << total;
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
