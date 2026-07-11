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

    int n, t;
    cin >> n >> t;
    t--;

    vector<ll> portals(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> portals[i];
    }

    set<ll> viewed_cells;
    ll current_cell = 0;
    while (true) {
        if (current_cell == t) {
            cout << "YES";
            return 0;
        }
        if (viewed_cells.count(current_cell) || current_cell >= n - 1) {
            cout << "NO";
            return 0;
        }
        viewed_cells.insert(current_cell);
        current_cell = current_cell + portals[current_cell];
    }
}
