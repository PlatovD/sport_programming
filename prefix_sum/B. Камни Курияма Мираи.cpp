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

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector sorted_v(v.begin(), v.end());
    sort(sorted_v.begin(), sorted_v.end());

    vector<ll> prefix(n + 1, 0), prefix_sorted(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    for (int i = 0; i < n; i++) {
        prefix_sorted[i + 1] = prefix_sorted[i] + sorted_v[i];
    }

    int m;
    cin >> m;
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            cout << prefix[r] - prefix[l - 1] << '\n';
        }

        if (type == 2) {
            cout << prefix_sorted[r] - prefix_sorted[l - 1] << '\n';
        }
    }
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
