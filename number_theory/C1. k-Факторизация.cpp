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
    ll n, k;
    cin >> n >> k;

    vector<ll> divs;

    while (n % 2 == 0) {
        n /= 2;
        divs.push_back(2);
    }

    for (int i = 3; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            divs.push_back(i);
        }
    }

    if (n > 1) divs.push_back(n);

    if (divs.size() < k) {
        cout << -1;
        return;
    }

    if (divs.size() > k) {
        for (int i = divs.size() - 1; i >= k; i--) {
            divs[k - 1] *= divs[i];
        }
    }
    for (int i = 0; i < k; i++) {
        cout << divs[i] << " ";
    }
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
