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
    int q;
    cin >> q;
    map<string, string> old_new;

    string old, neew;
    while (q--) {
        cin >> old >> neew;
        if (old_new.count(old)) {
            string start_name = old_new[old];
            old_new.erase(old);
            old_new[neew] = start_name;
        } else {
            old_new[neew] = old;
        }
    }
    cout << old_new.size() << '\n';
    for (auto &kv: old_new) {
        cout << kv.second << " " << kv.first << '\n';
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
