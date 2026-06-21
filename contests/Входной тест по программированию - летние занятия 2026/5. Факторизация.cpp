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

    ll n;
    cin >> n;

    ll cnt = 0;
    while (n % 2 == 0 && n > 0) {
        n /= 2;
        cnt++;
    }
    if (cnt)
        cout << 2 << ' ' << cnt << endl;

    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            cnt = 0;
            while (n % i == 0 && n > 0) {
                n /= i;
                cnt++;
            }
            cout << i << ' ' << cnt << endl;
        }
    }

    if (n > 1) {
        cout << n << ' ' << 1 << endl;
    }
}
