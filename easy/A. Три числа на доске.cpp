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
    vector<ll> inp(3);
    for (int i = 0; i < 3; i++) cin >> inp[i];
    sort(inp.begin(), inp.end());

    vector do_nothing(inp.begin(), inp.end());
    vector increase_min(inp.begin(), inp.end());
    vector decrease_max(inp.begin(), inp.end());

    increase_min[0] = increase_min[1] + increase_min[2];
    sort(increase_min.begin(), increase_min.end());

    decrease_max[2] = decrease_max[0] + decrease_max[1];
    sort(decrease_max.begin(), decrease_max.end());

    cout << min(min(increase_min[2] - increase_min[0], decrease_max[2] - decrease_max[0]),
                do_nothing[2] - do_nothing[0]) << '\n';
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
