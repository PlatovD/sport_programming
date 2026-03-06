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
    int q;
    cin >> n;
    cin >> q;

    ll a;
    while (q--) {
        cin >> a;
        if (abs(a) == 0) {
            cout << 0 << '\n';
            continue;
        }
        if (abs(a) == 1) {
            cout << 1 << '\n';
            continue;
        }
        if (a % 2 == 0) {
            cout << -1 << '\n';
            continue;
        }

        a = abs(a);
        ll step = 1;
        int cnt = 0;
        while (a > step) {
            step *= 2;
            cnt++;
        }
        cout << cnt << '\n';
    }
}
