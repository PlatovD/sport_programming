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
    int n, k;
    cin >> n >> k;

    vector res(n, -1);
    int current_num = 1;
    int max_inv = n - 1;
    while (true) {
        if (k >= max_inv) {
            res[n - current_num] = current_num;
            k -= max_inv;
            current_num++;
            max_inv--;
        } else {
            res[n - current_num - (max_inv - k)] = current_num;
            k -= max_inv;
            current_num++;
            max_inv--;
        }

        if (k <= 0) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (res[i] == -1) res[i] = current_num++;
    }

    for (auto el: res) {
        cout << el << ' ';
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
