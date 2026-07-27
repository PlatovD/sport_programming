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

    unordered_map<ll, ll> can;
    unordered_map<ll, ll> moves_to_reach_sum;

    vector<int> good;

    int num;
    for (int i = 0; i < n; i++) {
        int moves = 0;
        cin >> num;

        if (num == 1) {
            can[num]++;
            if (can[num] == n) {
                good.push_back(num);
            }
            moves_to_reach_sum[num] += 0;

            can[2]++;
            if (can[2] == n) {
                good.push_back(2);
            }
            moves_to_reach_sum[2] += 1;
            continue;
        }

        while (num > 1) {
            if (i == 0 || (can.find(num) != can.end() && can[num] == i)) {
                can[num]++;
                if (can[num] == n) {
                    good.push_back(num);
                }
                moves_to_reach_sum[num] += moves;
            }

            moves++;
            if (num % 2 == 0)
                num /= 2;
            else num += 1;
        }

        can[1]++;
        if (can[1] == n) {
            good.push_back(num);
        }
        moves_to_reach_sum[1] += moves;
    }

    ll min_moves = INT64_MAX;
    for (auto pos: good) {
        min_moves = min(min_moves, moves_to_reach_sum[pos]);
    }

    cout << min_moves << '\n';
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
