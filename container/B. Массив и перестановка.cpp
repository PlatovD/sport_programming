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
    vector<int> p(n), a(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, int> index_of_number_in_permutation;
    for (int i = 0; i < n; i++) {
        index_of_number_in_permutation[p[i]] = i;
    }

    int max_prev_index = -1;
    for (int i = 0; i < n; i++) {
        int index_ai = index_of_number_in_permutation[a[i]];
        if (index_ai < max_prev_index) {
            cout << "NO" << '\n';
            return;
        }
        max_prev_index = index_ai;
    }
    cout << "YES" << '\n';
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
    cin >> t;
    while (t--) {
        solve();
    }
}
