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
using namespace std;

// шаблон
int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector a(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector prefix_2d(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefix_2d[i + 1][j + 1] = a[i][j] + prefix_2d[i][j + 1] + prefix_2d[i + 1][j] - prefix_2d[i][j];
        }
    }

    int q;
    cin >> q;
    int lx, ly, rx, ry;
    while (q--) {
        cin >> lx >> ly >> rx >> ry;
        cout << prefix_2d[rx][ry] - prefix_2d[lx - 1][ry] - prefix_2d[rx][ly - 1] + prefix_2d[lx - 1][ly - 1] << '\n';
    }
}
