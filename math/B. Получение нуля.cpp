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

struct state {
    int current_remainder;
    int cnt_steps;
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mod = 32768;

    vector steps_cnt(32768, -1);

    queue<state> q;
    q.push({0, 0});
    steps_cnt[0] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.current_remainder % 2 == 0) {
            int prev1 = cur.current_remainder / 2;
            if (steps_cnt[prev1] == -1) {
                steps_cnt[prev1] = cur.cnt_steps + 1;
                q.push({prev1, cur.cnt_steps + 1});
            }

            int prev2 = cur.current_remainder / 2 + mod / 2;
            if (steps_cnt[prev2] == -1) {
                steps_cnt[prev2] = cur.cnt_steps + 1;
                q.push({prev2, cur.cnt_steps + 1});
            }
        }

        int next_rem = (cur.current_remainder - 1 + mod) % mod;
        if (steps_cnt[next_rem] == -1) {
            steps_cnt[next_rem] = cur.cnt_steps + 1;
            q.push({next_rem, cur.cnt_steps + 1});
        }
    }

    for (int i = 0; i < n; i++) {
        cout << steps_cnt[a[i]] << ' ';
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
