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
        int l, r;
        cin >> l >> r;

        int p0, p1, p2;
        p0 = l;
        p1 = l + 1;
        p2 = l + 2;
        int cnt = 0;
        while (p2 <= r) {
            if (gcd(p0, p1) == gcd(p1, p2) == gcd(p2, p0) == 1) {
                cnt++;
                p0 += 3;
                p1 += 3;
                p2 += 3;
            } else {
                p0 += 1;
                p1 += 1;
                p2 += 1;
            }
        }
        cout << cnt << endl;
    }
}
