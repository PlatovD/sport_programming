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
        ll n, k;
        cin >> n >> k;
        if (k > n) {
            cout << -1 << '\n';
            continue;
        }
        if (k == n) {
            cout << 0 << '\n';
            continue;
        }

        bool success = false;
        int total_time = 0;
        while (n > 1) {
            total_time++;
            ll last_n = n;
            n /= 2;
            ll first_pile = n;
            ll second_pile = n + last_n % 2;
            if (first_pile == k || second_pile == k) {
                cout << total_time << '\n';
                success = true;
                break;
            }
            if (first_pile % 2 == 1)
                n = first_pile;
            else
                n = second_pile;
        }
        if (!success)
            cout << -1 << '\n';
    }
}
