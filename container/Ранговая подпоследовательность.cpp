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

bool is_inside(int j, pair<int, int> borders) {
    return borders.first <= j && j <= borders.second;
}

bool check(int m, vector<pair<int, int> > &l_r, vector<pair<int, int> > &u_v) {
    int left = m;
    int j = 1;
    for (int i = 0; i < l_r.size() && left > 0; i++) {
        if (!is_inside(j, l_r[i]) && !is_inside(m - j + 1, u_v[i])) {
            left--;
            j++;
        }
    }
    return left == 0;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int> > l_r(n);
    vector<pair<int, int> > u_v(n);

    int l, r, u, v;
    for (int i = 0; i < n; i++) {
        cin >> l >> r >> u >> v;
        l_r[i] = {l, r};
        u_v[i] = {u, v};
    }

    int ans = 0;
    for (int m = 1; m < n + 1; m++) {
        if (check(m, l_r, u_v)) {
            ans = max(ans, m);
        }
    }

    cout << ans << '\n';
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
