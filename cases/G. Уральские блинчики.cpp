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
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];

    int pancakes_odd = 0, pancakes_even = 0, places_odd = 0, places_even = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                if ((i + j) % 2 == 0) {
                    places_even++;
                } else {
                    places_odd++;
                }
            }
            if (g[i][j] == 'P') {
                if ((i + j) % 2 == 0) {
                    pancakes_even++;
                } else {
                    pancakes_odd++;
                }
            }
        }
    }

    if (pancakes_even == 1 && pancakes_odd == 1 && places_even + places_odd == 0) {
        cout << "NO";
        return;
    }

    // иначе могу обменять на четных и на нечет местах
    int min_pancakes = min(pancakes_even, pancakes_odd);
    pancakes_even -= min_pancakes;
    pancakes_odd -= min_pancakes;
    if (pancakes_even > 0) {
        pancakes_even = max(0, pancakes_even - places_odd);
    }
    if (pancakes_odd > 0) {
        pancakes_odd = max(0, pancakes_odd - places_even);
    }
    if (pancakes_even == 0 && pancakes_odd == 0) {
        cout << "YES";
    } else {
        cout << "NO";
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
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
