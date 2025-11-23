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

#define ll long long
using namespace std;

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
    for (int q = 0; q < t; q++) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (auto &el: a) cin >> el;
        for (auto &el: b) cin >> el;

        int cnt1_first = 0;
        int cnt1_second = 0;
        int last_change_situation = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) cnt1_first++;
            if (b[i] == 1) cnt1_second++;
            if (a[i] != b[i]) {
                last_change_situation = i % 2;
            }
        }

        if (cnt1_first % 2 == cnt1_second % 2) {
            cout << "Tie" << '\n';
            continue;
        }
        if (last_change_situation == -1) {
            if (cnt1_first % 2 == 1) {
                cout << "Ajisai" << '\n';
                continue;
            }
            cout << "Mai" << '\n';
            continue;
        }
        if (last_change_situation == 0) {
            cout << "Ajisai" << '\n';
        } else {
            cout << "Mai" << '\n';
        }
    }
}
