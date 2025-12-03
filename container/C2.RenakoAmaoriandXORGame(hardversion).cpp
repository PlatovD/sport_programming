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

bool exists_bit(int num, int bit) {
    return (num >> bit) & 1;
}

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
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            a[i] = num;
        }
        for (int i = 0; i < n; i++) {
            cin >> num;
            b[i] = num;
        }

        int s = a[0] ^ b[0];
        for (int i = 1; i < n; i++) {
            s ^= a[i];
            s ^= b[i];
        }
        if (s == 0) {
            cout << "Tie" << '\n';
            continue;
        }
        int highest_bit = __bit_width(s) - 1;
        bool is_aj_wins = true;
        for (int i = 0; i < n; i++) {
            if (exists_bit(a[i], highest_bit) && exists_bit(b[i], highest_bit)) {
                continue;
            }
            if (i % 2 == 0 && (exists_bit(a[i], highest_bit) || exists_bit(b[i], highest_bit))) {
                is_aj_wins = true;
            } else if (i % 2 == 1 && (exists_bit(a[i], highest_bit) || exists_bit(b[i], highest_bit))) {
                is_aj_wins = false;
            }
        }
        if (is_aj_wins) {
            cout << "Ajisai" << '\n';
        } else {
            cout << "Mai" << '\n';
        }
    }
}
