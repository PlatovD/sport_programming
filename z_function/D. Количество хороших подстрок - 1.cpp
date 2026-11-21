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

struct bad_pos {
    ll start_index;
    ll end_index;
};

void solve() {
    string s, t;
    cin >> s >> t;

    ll n = s.size();
    ll m = t.size();

    vector<bad_pos> bad_positions;
    bad_positions.push_back({-1, 0});
    for (ll i = 0; i <= n - m; i++) {
        bool bad = true;
        for (ll j = i; j < m + i; j++) {
            if (s[j] != t[j - i]) {
                bad = false;
                break;
            }
        }

        if (bad) bad_positions.push_back({i, i + m - 1});
    }
    bad_positions.push_back({n, n});

    ll total = 0;
    for (ll i = 0; i < bad_positions.size() - 1; i++) {
        bad_pos current = bad_positions[i];
        bad_pos next = bad_positions[i + 1];

        ll from_start = current.start_index + 1;
        ll end_index = next.end_index - 1;

        ll k = end_index - from_start + 1;
        total += (k + 1) * k / 2;
    }

    // вычет пересечений, учтенных дважды
    if (m > 2) {
        total -= ((ll) bad_positions.size() - 2) * (m - 2) * (m - 1) / 2;
    }

    cout << total << '\n';
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
