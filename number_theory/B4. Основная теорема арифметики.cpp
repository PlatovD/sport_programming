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

    ll n, start_n;
    cin >> n;
    start_n = n;
    map<ll, ll> divs;

    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            divs[i] += 1;
        }
    }
    if (n > 1) divs[n] = 1;

    string ans;
    ans.reserve(100);
    ans += to_string(start_n) + "=";
    bool is_first = true;
    for (auto kv: divs) {
        for (int j = 0; j < kv.second; j++) {
            if (is_first) {
                ans += to_string(kv.first);
                is_first = false;
            } else {
                ans += "*" + to_string(kv.first);
            }
        }
    }
    cout << ans;
}
