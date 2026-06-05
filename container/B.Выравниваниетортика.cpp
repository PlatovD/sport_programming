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
        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll prefix_sum = a[0];
        ll prefix_best_h = a[0];
        cout << prefix_best_h << ' ';
        for (int i = 1; i < n; i++) {
            if (prefix_best_h < a[i]) {
            } else {
                prefix_best_h = min(prefix_best_h, (prefix_sum + a[i]) / (i + 1));
            }
            cout << prefix_best_h << ' ';
            prefix_sum += a[i];
        }
    }
}
