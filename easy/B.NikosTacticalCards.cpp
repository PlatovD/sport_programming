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
        vector<ll> a(n);
        vector<ll> b(n);
        for (auto &el: a) cin >> el;
        for (auto &el: b) cin >> el;

        ll min_sum = 0;
        ll max_sum = 0;
        for (int i = 0; i < n; i++) {
            ll last_min = min_sum;
            ll last_max = max_sum;
            max_sum = max(max(last_min - a[i], b[i] - last_min), max(last_max - a[i], b[i] - last_max));
            min_sum = min(min(last_min - a[i], b[i] - last_min), min(last_max - a[i], b[i] - last_max));
        }
        cout << max_sum << '\n';
    }
}
