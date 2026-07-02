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

    ll p1, q1, p2, q2;
    cin >> p1 >> q1 >> p2 >> q2;

    if (p1 < 0 && q1 < 0) {
        p1 = abs(p1);
        q1 = abs(q1);
    }

    if (p2 < 0 && q2 < 0) {
        p2 = abs(p2);
        q2 = abs(q2);
    }

    if (q1 < 0) {
        p1 = -p1;
        q1 = abs(q1);
    }

    if (q2 < 0) {
        p2 = -p2;
        q2 = abs(q2);
    }

    ll noc = q1 / gcd(q1, q2) * q2;
    ll coef_1 = noc / q1, coef_2 = noc / q2;
    p1 *= coef_1;
    p2 *= coef_2;

    ll p = p1 + p2;
    ll q = noc;

    ll g = gcd(abs(p), q);
    p /= g;
    q /= g;

    if (p == 0) {
        cout << 0 << ' ' << 1 << endl;
    } else {
        cout << p << ' ' << q << endl;
    }
}
