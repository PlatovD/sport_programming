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

bool check(int r, vector<int> &a, vector<int> &b) {
    int current_city = 0;
    int current_tower = 0;
    while (current_city < a.size() && current_tower < b.size()) {
        if (abs(a[current_city] - b[current_tower]) <= r) {
            current_city++;
        } else {
            current_tower++;
        }
    }
    return current_city == a.size();
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = INT32_MAX;
    int l = 0, r = 2 * 1e9 + 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid, a, b)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
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
