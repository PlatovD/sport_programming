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
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<ll> balances(n);
        for (auto &el: balances) cin >> el;

        // первым проходом найду оптимальный банк, откуда при переводах максимально теряю
        // вторым проходом посчитаю

        int index_of_max_lost = 0;
        ll max_lost = 0;
        for (int i = 0; i < n; i++) {
            ll can_transfer = balances[i] / x * y;
            ll lost = balances[i] - can_transfer;
            if (lost > max_lost) {
                max_lost = lost;
                index_of_max_lost = i;
            }
        }

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (i == index_of_max_lost) {
                sum += balances[i];
            } else {
                sum += y * (balances[i] / x);
            }
        }

        cout << sum << '\n';
    }
}
