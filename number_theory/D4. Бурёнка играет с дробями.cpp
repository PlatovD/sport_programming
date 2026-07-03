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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a == 0 && c == 0) {
            cout << 0 << endl;
            continue;
        }

        ll p = c * b, q = a * d;
        if (p == 0 || q == 0) {
            cout << 1 << endl;
            continue;
        }

        ll g = gcd(p, q);
        p /= g;
        q /= g;
        if (p == q) {
            cout << 0 << endl;
            continue;
        }
        if (p == 1 || q == 1) {
            cout << 1 << endl;
            continue;
        }
        cout << 2 << endl;
    }
}
