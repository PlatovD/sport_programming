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
    int n;
    cin >> n;
    vector colors(n + 2, 1);
    colors[0] = 1;
    colors[1] = 1;
    for (ll i = 2; i <= n + 1; i++) {
        for (ll j = i * i; j <= n + 1; j += i) {
            colors[j] = 2;
        }
    }

    int ma = 0;
    for (int i = 2; i <= n + 1; i++) {
        ma = max(colors[i], ma);
    }
    cout << ma << '\n';

    for (int i = 2; i <= n + 1; i++) {
        cout << colors[i] << " ";
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
