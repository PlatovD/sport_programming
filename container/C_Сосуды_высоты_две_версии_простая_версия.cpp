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
        int n;
        cin >> n;

        vector<ll> h(2 * n);
        for (int i = 0; i < n; i++) cin >> h[i];
        for (int i = 0; i < n; i++) {
            h[n + i] = h[i];
        }

        vector<ll> res(n);
        for (int i = 0; i < n; i++) {
            // i - то, что с 0 уровнем воды
            vector<ll> left_borders(n);
            left_borders[0] = 0;
            for (int j = 1; j < n; j++) {
                left_borders[j] = max(left_borders[j - 1], h[i + j - 1]);
            }


            vector<ll> right_borders(n);
            right_borders[n - 1] = 0;
            for (int j = 1; j < n; j++) {
                right_borders[j] = max(right_borders[j - 1], h[i + n - j]);
            }

            ll total = 0;
            for (int j = 1; j < n; j++) {
                total += min(left_borders[j], right_borders[n - j]);
            }
            cout << total << ' ';
        }
        cout << endl;
    }
}
