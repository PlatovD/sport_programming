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
    int n, k;
    cin >> n >> k;

    vector<int> dist(n);
    for (int i = 0; i < n; i++) cin >> dist[i];
    sort(dist.begin(), dist.end());

    vector<int> pos;
    for (int cnt_long = n; cnt_long > -1; cnt_long--) {
        if (cnt_long * 3 + 2 * (n - cnt_long) == k) {
            if (cnt_long == n) {
                pos.push_back(0);
            } else {
                pos.push_back(dist[n - cnt_long - 1] + 1);
            }
        }
    }
    sort(pos.begin(), pos.end());
    cout << pos[0];
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
