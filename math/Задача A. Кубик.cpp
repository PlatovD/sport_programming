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

struct cube {
    int top, bottom, left, right, front, back;
};

cube move_forward(cube c) {
    return {c.back, c.front, c.left, c.right, c.top, c.bottom};
}

cube move_backward(cube c) {
    return {c.front, c.back, c.left, c.right, c.bottom, c.top};
}

cube move_left(cube c) {
    return {c.right, c.left, c.top, c.bottom, c.front, c.back};
}

cube move_right(cube c) {
    return {c.left, c.right, c.bottom, c.top, c.front, c.back};
}

void solve() {
    string s;
    cin >> s;

    // соответствие координаты и стороны кубика
    map<pair<int, int>, int> mp;
    cube c = {5, 0, 1, 2, 3, 4};
    mp[{0, 0}] = c.bottom;
    pair coord = {0, 0};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'L') {
            coord.first--;
            c = move_left(c);
            mp[coord] = c.bottom;
        }
        if (s[i] == 'R') {
            coord.first++;
            c = move_right(c);
            mp[coord] = c.bottom;
        }
        if (s[i] == 'U') {
            coord.second++;
            c = move_forward(c);
            mp[coord] = c.bottom;
        }
        if (s[i] == 'D') {
            coord.second--;
            c = move_backward(c);
            mp[coord] = c.bottom;
        }
    }

    vector counts(6, 0);
    for (auto kv: mp) {
        counts[kv.second]++;
    }

    sort(counts.begin(), counts.end());
    ll total = 0;
    for (int i = 0; i < counts.size(); i++) {
        total += (i + 1) * counts[i];
    }
    cout << total;
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
