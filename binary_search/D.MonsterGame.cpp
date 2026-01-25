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
#include<set>
#include <cstdint>
#include <set>
#include <algorithm>
#include <random>
#include <iomanip>
#include <assert.h>
#include <functional>
#include <memory>

#define ll long long
using namespace std;

ll can_reach_level(ll cnt_swords, vector<ll> &prefix_monsters) {
    ll l = 0;
    ll r = prefix_monsters.size() - 1;
    while (l < r) {
        ll m = (l + r + 1) / 2;
        if (prefix_monsters[m] > cnt_swords) {
            r = m - 1;
        } else {
            l = m;
        }
    }
    return l;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> swords(n);
        for (auto &el: swords) cin >> el;
        sort(swords.begin(), swords.end());
        vector<ll> monsters(n);
        for (auto &el: monsters) cin >> el;
        vector<ll> prefix_monsters(n + 1);
        prefix_monsters[0] = 0;
        for (int i = 0; i < n; i++) {
            prefix_monsters[i + 1] = prefix_monsters[i] + monsters[i];
        }

        ll best = 0;
        ll cnt_swords = n;
        for (int i = 0; i < n; i++) {
            ll died = can_reach_level(cnt_swords, prefix_monsters);
            best = max(best, died * swords[i]);
            cnt_swords--;
        }
        cout << best << '\n';
    }
    return 0;
}