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

ld EPS = 1e-12;


void solve() {
    ld k, R;
    cin >> k >> R;

    vector<ld> known(k);
    for (int i = 0; i < k; i++) cin >> known[i];

    ld l = 0, r = 1e12;
    while (abs(r - l) > EPS) {
        ld mid = l + (r - l) / 2;
        ld sum = 0;
        for (int i = 0; i < k; i++) {
            sum += known[i] * mid / (known[i] + mid);
        }
        if (sum > R) r = mid;
        else l = mid;
    }
    cout << l;
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
