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

    ll n;
    cin >> n;
    map<ll, ll> divs;

    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            divs[i] += 1;
        }
    }
    if (n > 1) divs[n] = 1;
    for (auto kv: divs) {
        cout << kv.first << " " << kv.second << '\n';
    }
}
