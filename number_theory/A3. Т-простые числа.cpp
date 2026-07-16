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
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;


void solve() {
    int n;
    cin >> n;
    ll num;
    vector is_simple(1e6 + 1, true);
    is_simple[0] = false;
    is_simple[1] = false;
    for (ll i = 2; i <= 1e6; i++) {
        if (!is_simple[i]) continue;
        for (ll j = i * i; j <= 1e6; j += i) {
            is_simple[j] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (sqrt(num) == ceil(sqrt(num)) && is_simple[(int) sqrt(num)]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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

    solve();
}
