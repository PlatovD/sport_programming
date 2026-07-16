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
    ll n;
    cin >> n;

    set<ll> lost_start_positions;
    ll pos = 1;
    ll magnifier = 2;
    while (pos <= n && pos > 0) {
        lost_start_positions.insert(pos);
        pos += magnifier;
        magnifier *= 2;
    }
    if (lost_start_positions.find(n) != lost_start_positions.end()) {
        cout << "Second";
    } else {
        cout << "First";
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
