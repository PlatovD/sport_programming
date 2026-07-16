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
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;


void solve() {
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    vector<vector<double> > m{{a, b, c}, {d, e, f}};
    if (a == 0)
        swap(m[0], m[1]);

    double coef = -m[1][0] / m[0][0];
    for (int i = 0; i < 3; i++) {
        m[1][i] += m[0][i] * coef;
    }

    double y = m[1][2] / m[1][1];
    double x = (m[0][2] - m[0][1] * y) / m[0][0];
    cout << x << ' ' << y;
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

    solve();
}
