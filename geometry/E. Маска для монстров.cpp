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
    ll n;
    cin >> n;

    vector<ld> distances(n);

    ld last_x, last_y;
    ld start_x, start_y;

    cin >> last_x >> last_y;
    start_x = last_x;
    start_y = last_y;

    ld total_dist = 0;
    for (int i = 0; i < n - 1; i++) {
        ld x, y;
        cin >> x >> y;
        ld cur_dist = sqrt((x - last_x) * (x - last_x) + (y - last_y) * (y - last_y));
        distances[i] = cur_dist;
        total_dist += cur_dist;
        last_x = x;
        last_y = y;
    }

    ld cur_dist = sqrt((start_x - last_x) * (start_x - last_x) + (start_y - last_y) * (start_y - last_y));
    distances[n - 1] = cur_dist;
    total_dist += cur_dist;


    sort(distances.begin(), distances.end());
    total_dist -= distances.back();
    cout << total_dist;
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
