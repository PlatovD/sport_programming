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

    int left_border = 1;
    int right_border = n;

    int l = 0;
    int r = n - 1;

    while (l < r) {
        if (a[l] == left_border) {
            l++;
            left_border++;
            continue;
        }

        if (a[l] == right_border) {
            l++;
            right_border--;
            continue;
        }

        if (a[r] == left_border) {
            r--;
            left_border++;
            continue;
        }

        if (a[r] == right_border) {
            r--;
            right_border--;
            continue;
        }

        cout << l + 1 << ' ' << r + 1 << '\n';
        return;
    }

    cout << -1 << '\n';
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
