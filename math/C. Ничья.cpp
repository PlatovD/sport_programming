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
    //система
    // нужно чтобы было p=win_cnt*k + draw_cnt
    // при этом еще win_cnt+draw_cnt<=n, иначе надо больше матчей
    ll n, p, k;
    cin >> n >> p >> k;
    ll win_cnt;
    if (p > n)
        win_cnt = (p - n + k - 2) / (k - 1);
    else win_cnt = 0;
    ll draw_cnt = p - k * win_cnt;
    if (draw_cnt < 0 || win_cnt + draw_cnt > n) {
        cout << -1;
        return;
    }
    cout << draw_cnt;
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
