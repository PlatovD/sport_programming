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
using namespace std;

// шаблон
int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll l = 0, r = 1e18 + 1;
        ll good = -1;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            ll dividable = mid / n;
            ll not_dividable = mid - dividable;
            if (not_dividable == k) {
                good = mid % n == 0 ? mid - 1 : mid;
                break;
            }
            if (not_dividable < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << good << '\n';
    }
}
