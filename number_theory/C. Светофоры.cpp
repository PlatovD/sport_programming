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

ll cnt_divs_less_or_equal_a(ll num, ll a) {
    ll cnt = 0;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            if (i <= a)
                cnt++;
            if (num / i != i) {
                if (num / i <= a)
                    cnt++;
            }
        }
    }
    return cnt;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    if (a == b) {
        cout << min(a, b);
        return;
    }

    if (a > b) swap(a, b);
    ll diff = b - a;
    cout << cnt_divs_less_or_equal_a(diff, a);
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
