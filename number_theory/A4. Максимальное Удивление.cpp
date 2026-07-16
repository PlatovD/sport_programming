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
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;


void solve() {
    int n, x;
    cin >> n >> x;

    ll to = (ll) sqrt(2 * 1e9);
    vector is_simple(to, true);
    vector<ll> simples;
    is_simple[0] = false;
    is_simple[1] = false;
    for (ll i = 2; i <= to; i++) {
        if (!is_simple[i]) continue;
        simples.push_back(i);
        for (ll j = i * i; j <= to; j += i) {
            is_simple[j] = false;
        }
    }

    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    ll best_cnt = 0;
    ll best_num = 2;
    for (auto simple: simples) {
        int current_cnt = 0;
        if (simple > x) break;
        for (int i = 0; i < n; i++) {
            if (nums[i] % simple == 0) continue;
            current_cnt++;
        }
        if (current_cnt > best_cnt) {
            best_num = simple;
            best_cnt = current_cnt;
        }
    }
    cout << best_num;
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

    solve();
}
