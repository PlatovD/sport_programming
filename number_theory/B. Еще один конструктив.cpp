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
    int n, k, m;
    cin >> n >> k >> m;

    if (k > m) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    vector<int> sub_mas;
    for (int i = 0; i < k - 1; i++) {
        sub_mas.push_back(1);
    }
    sub_mas.push_back(m - k + 1);
    for (int i = 0; i < n; i++) {
        cout << sub_mas[i % sub_mas.size()] << " ";
    }
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
