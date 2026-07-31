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

    vector<string> all_strings(n);
    set<string> counts;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> all_strings[i];
        counts.insert(all_strings[i]);
    }

    for (int i = 0; i < n; i++) {
        const string &cur = all_strings[i];
        bool flag = false;
        for (int cut = 1; cut < all_strings[i].length(); cut++) {
            if (counts.count(cur.substr(0, cut)) && counts.count(cur.substr(cut))) {
                cout << 1;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << 0;
    }
    cout << '\n';
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
