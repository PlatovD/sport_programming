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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    int g = gcd(a, b);
    return a / g * b;
}

ll sum_divs(int num, int n) {
    ll res = 0;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            res += n / i;
            if (i != num / i)
                res += n / (num / i);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    // int cnt = 0;
    // for (int i = 1; i < n + 1; i++) {
    //     for (int j = 1; j < n + 1; j++) {
    //         for (int k = 1; k < n + 1; k++) {
    //             if (gcd(lcm(i, j), lcm(j, k)) == gcd(i, k)) {
    //                 cout << i << ' ' << j << ' ' << k << '\n';
    //                 cnt++;
    //             }
    //         }
    //     }
    // }
    // cout << cnt << '\n';

    ll cnt = 0;
    for (int i = 1; i < n + 1; i++)
        cnt += sum_divs(i, n);
    cout << cnt << '\n';
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
