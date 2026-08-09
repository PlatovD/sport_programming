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

struct liberation {
    ll window_number;
    ll time;
};

struct comparator {
    bool operator()(liberation a, liberation b) const {
        if (a.time != b.time) {
            return a.time > b.time;
        }
        return a.window_number > b.window_number;
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> x(m);
    vector<ll> y(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
        cin >> y[i];
    }


    priority_queue<liberation, vector<liberation>, comparator> pq;
    for (int i = 0; i < m; i++) {
        pq.push({i, 0});
    }

    ll latest_end_time = 0;
    vector<int> window_numbers(n);
    for (int i = 0; i < n; i++) {
        auto window_for_current = pq.top();
        pq.pop();
        window_numbers[i] = window_for_current.window_number;
        ll time_end = window_for_current.time + x[window_for_current.window_number] + y[window_for_current.
                          window_number] * a[i];
        latest_end_time = max(time_end, latest_end_time);
        pq.push({window_for_current.window_number, time_end});
    }
    cout << latest_end_time << '\n';
    for (auto num: window_numbers) {
        cout << num + 1 << ' ';
    }
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
    // cin >> t;
    while (t--) {
        solve();
    }
}
