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
    vector rooms(10, true);
    string actions;
    cin >> actions;
    for (int i = 0; i < n; i++) {
        char action = actions[i];
        if (action == 'R' || action == 'L') {
            if (action == 'L') {
                for (int j = 0; j < 10; j++)
                    if (rooms[j]) {
                        rooms[j] = false;
                        break;
                    }
            } else {
                for (int j = 9; j > -1; j--)
                    if (rooms[j]) {
                        rooms[j] = false;
                        break;
                    }
            }
        } else {
            int index = action - '0';
            rooms[index] = true;
        }
    }

    for (auto i: rooms) {
        cout << (i ? 0 : 1);
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
