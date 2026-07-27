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

void bad_sort(vector<int> &a) {
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = i; j < a.size() - 1; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    if (n <= 2) {
        cout << -1;
        return;
    }

    cout << 100 << ' ';
    for (int i = 1; i < n; i++) {
        cout << 100 - i << ' ';
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
