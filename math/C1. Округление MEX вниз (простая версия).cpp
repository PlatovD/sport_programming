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

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int> > bad_segments;
    for (int i = 0; i < n; i++) {
        bad_segments.push_back({(i + 1) * a[i], max((i + 1) * (a[i] + 1) - 1, 0)});
    }

    vector all_numbers(n, 0);
    for (auto p: bad_segments) {
        int l = p.first;
        int r = p.second + 1;

        if (l < n)
            all_numbers[l] += 1;
        if (r < n)
            all_numbers[r] -= 1;
    }

    vector result(n, 0);
    result[0] = all_numbers[0];
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] + all_numbers[i];
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (result[i] != 0) continue;
        ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (auto x: ans) cout << x << " ";
    cout << '\n';
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
