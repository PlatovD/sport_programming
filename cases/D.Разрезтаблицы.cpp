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

    ll t;
    cin >> t;
    while (t--) {
        ll m, n;
        cin >> n >> m;
        ll total_sum = 0;
        vector table(n + 1, vector(m + 1, 0));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cin >> table[i][j];
                total_sum += table[i][j];
            }
        }

        ll required = total_sum / 2;
        pair pointer = {n - 1, 0};
        while (required > 0) {
            required -= table[pointer.first][pointer.second];
            if (pointer.second == m - 1 && required != 0) {
                pointer.first -= 1;
                pointer.second = 0;
            } else {
                pointer.second += 1;
            }
        }
        cout << total_sum / 2 * (total_sum - total_sum / 2) << '\n';
        ll down_steps = n;
        ll right_steps = m;
        for (int i = 0; i < pointer.first && down_steps > 0; i++) {
            cout << "D";
            down_steps--;
        }
        for (int i = 0; i < pointer.second && right_steps > 0; i++) {
            cout << "R";
            right_steps--;
        }
        if (down_steps > 0) {
            cout << "D";
            down_steps--;
        }

        while (right_steps > 0) {
            right_steps--;
            cout << "R";
        }
        while (down_steps > 0) {
            down_steps--;
            cout << "D";
        }
        cout << '\n';
    }
}
