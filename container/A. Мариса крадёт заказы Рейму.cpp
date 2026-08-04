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

    map<int, int> counts;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        counts[num]++;
    }

    int total = 0;
    total += min(counts[1], counts[2]);
    counts[1] -= total;
    counts[2] -= total;
    if (counts[1] > 0) {
        total += counts[1] / 3;
    }
    if (counts[2] > 0) {
        total += counts[2] / 3;
    }
    total += counts[0];

    cout << total << '\n';
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
