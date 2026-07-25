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
    int n;
    cin >> n;

    map<int, ll> mp;

    int num;
    while (n--) {
        cin >> num;
        for (int i = 2; i * i <= num; i++) {
            while (num % i == 0) {
                num /= i;
                mp[i]++;
            }
        }
        if (num > 1) mp[num]++;
    }

    ll res = 1;
    for (auto kv: mp) {
        res = res * ((kv.second + 1) % MOD) % MOD;
    }
    cout << res;
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
