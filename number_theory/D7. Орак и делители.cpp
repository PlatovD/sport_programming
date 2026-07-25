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

vector sieve(1e6 + 1, INT32_MAX);

void solve() {
    ll n, k;
    cin >> n >> k;

    if (n % 2 == 0) {
        cout << n + 2 * k << '\n';
    } else {
        k--;
        if (sieve[n] != INT32_MAX) {
            n += sieve[n];
        } else {
            n *= 2;
        }
        cout << n + 2 * k << '\n';
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

    for (int i = 2; i * i <= 1e6; i++) {
        if (sieve[i] != INT32_MAX) continue;
        for (int j = i * i; j <= 1e6; j += i) {
            sieve[j] = min(sieve[j], i);
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
