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
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll best_sum = a[0];
        ll current_sum = a[0];
        ll last_num = a[0];
        for (int i = 1; i < n; i++) {
            if (abs(a[i]) % 2 == abs(last_num) % 2) {
                current_sum = a[i];
            } else {
                if (current_sum + a[i] < a[i]) {
                    current_sum = a[i];
                } else {
                    current_sum += a[i];
                }
            }
            last_num = a[i];
            best_sum = max(best_sum, current_sum);
        }
        cout << best_sum << '\n';
    }
}
