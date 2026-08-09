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
    // ним с несколькими кучками
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
        mp[s[i]]++;

    int res_xor = 0;
    set<int> mex_1, mex_2, mex_3;
    for (int i = 1; i <= 40; i += 3) {
        mex_1.insert(i);
    }
    for (int i = 2; i <= 40; i += 3) {
        mex_2.insert(i);
    }
    for (int i = 3; i <= 40; i += 3) {
        mex_3.insert(i);
    }
    for (auto kv: mp) {
        // mex = 0 только в 0. Из остальных в него можно перейти значит там mex!= 0. И он меняется от 1 до 3.В 1 - 1б 2-2
        if (mex_1.count(kv.second)) {
            res_xor ^= 1;
        }
        if (mex_2.count(kv.second)) {
            res_xor ^= 2;
        }
        if (mex_3.count(kv.second)) {
            res_xor ^= 3;
        }
    }
    if (res_xor == 0) {
        cout << "Bob";
    } else {
        cout << "Alice";
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
