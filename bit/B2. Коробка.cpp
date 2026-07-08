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
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;

// шаблон
int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, w;
        cin >> n >> w;
        multiset<ll> mset;
        ll num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            mset.insert(num);
        }

        ll levels_cnt = 0;
        while (!mset.empty()) {
            ll level_remaining = w;
            while (!mset.empty()) {
                auto it = mset.upper_bound(level_remaining);
                if (it == mset.begin()) {
                    break;
                }
                --it;
                level_remaining -= *it;
                mset.erase(it);
            }
            levels_cnt++;
        }
        cout << levels_cnt << endl;
    }
}
