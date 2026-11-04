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
double eps = 1e-7;


double check(double x, vector<double> &positions, vector<double> &wearing_t) {
    double max_time = -1;
    for (int i = 0; i < wearing_t.size(); i++) {
        max_time = max(wearing_t[i] + abs(x - positions[i]), max_time);
    }
    return max_time;
}


void solve() {
    int n;
    cin >> n;
    vector<double> positions(n), wearing_t(n);
    double max_x = -1;
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
        max_x = max(positions[i], max_x);
    }
    for (int i = 0; i < n; i++) cin >> wearing_t[i];

    double l = 0, r = max_x;
    while (r - l >= eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        double time_m1 = check(m1, positions, wearing_t);
        double time_m2 = check(m2, positions, wearing_t);
        if (time_m1 > time_m2) {
            l = m1;
        } else {
            r = m2;
        }
    }

    cout << l << '\n';
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
