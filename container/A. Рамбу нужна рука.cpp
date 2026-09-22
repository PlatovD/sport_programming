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

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<int> bad;
    for (int i = 0; i < n; i++) {
        if (i + 1 != p[i])
            bad.push_back(p[i]);
    }

    bool un_able_to_make = false;
    for (int i = 1; i < bad.size(); i++) {
        if (bad[i - 1] < bad[i]) {
            un_able_to_make = true;
            break;
        }
    }

    if (un_able_to_make) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
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
    cin >> t;
    while (t--) {
        solve();
    }
}
