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
#include<set>
#include <cstdint>
#include <set>
#include <algorithm>
#include <random>
#include <iomanip>
#include <assert.h>

#define ll long long
using namespace std;

ll can_reach(ll balls) {
    return balls * (balls - 1) / 2;
}

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
        ll n;
        cin >> n;
        ll l = 2;
        ll r = 2648956421;
        ll ans = 2;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (can_reach(mid) > n) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }
        cout << ans + (n - can_reach(ans)) << '\n';
    }
}
