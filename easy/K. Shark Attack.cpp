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

    vector<ll> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    ll y;
    cin >> y;

    ll z;
    cin >> z;

    ll shark_to_bunker = abs(z - y);
    vector<ll> diffs(n);
    for (int i = 0; i < n; i++) {
        diffs[i] = abs(x[i] - z);
    }
    sort(diffs.begin(), diffs.end());

    ll current_pref = 0;
    int total = 0;
    while (current_pref < shark_to_bunker && total < n) {
        current_pref += diffs[total];
        if (current_pref >= shark_to_bunker) {
            break;
        }
        total++;
    }
    cout << total;
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
