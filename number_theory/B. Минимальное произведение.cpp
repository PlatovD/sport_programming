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
    ll n;
    cin >> n;

    vector<ll> indexes_a(n + 1);
    vector<ll> indexes_b(n + 1);
    ll key;
    for (int i = 0; i < n; i++) {
        cin >> key;
        indexes_a[key] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> key;
        indexes_b[key] = i;
    }
    // ибо всегда могу найти пару как максимум 1 * n
    ll top_border = n;
    vector min_for_current_shift(n, top_border);
    for (ll first_factor = 1; first_factor <= top_border; first_factor++) {
        ll second_factor = 1;
        while (second_factor <= n && first_factor * second_factor < top_border) {
            int a_index = indexes_a[first_factor];
            int b_index = indexes_b[second_factor];
            if (a_index >= b_index) {
                min_for_current_shift[a_index - b_index] = min(min_for_current_shift[a_index - b_index],
                                                               first_factor * second_factor);
            } else {
                min_for_current_shift[a_index + n - b_index] = min(min_for_current_shift[a_index + n - b_index],
                                                                   first_factor * second_factor);
            }
            second_factor++;
        }
    }

    for (int i = 0; i < n; i++) cout << min_for_current_shift[i] << "\n";
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
