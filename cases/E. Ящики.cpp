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


void solve() {
    ll n;
    cin >> n;

    vector<ll> a(2 * n - 1);
    ll sum = 0;
    for (int i = 0; i < 2 * n - 1; i += 2) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % (2 * n - 1) != 0) {
        cout << "NO";
        return;
    }

    ll req = sum / (2 * n - 1);
    for (int i = 1; i < 2 * n - 1; i += 2) {
        if (a[i - 1] > req) {
            a[i] += a[i - 1] - req;
            a[i - 1] = req;
        }
        if (a[i] < req) {
            int diff = req - a[i];
            a[i + 1] -= diff;
            a[i] += diff;
        }
    }

    bool bad = false;
    for (int i = 0; i < 2 * n - 1; i++) {
        if (a[i] != req) {
            bad = true;
            break;
        }
    }

    if (bad) {
        cout << "NO";
        return;
    }
    cout << "YES";
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
