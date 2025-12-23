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

struct Comparator {
    bool operator()(pair<ll, ll> p1, pair<ll, ll> p2) {
        return p1.second < p2.second;
    }
};

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
        for (auto &el: a) cin >> el;
        vector<ll> prefix(n + 1);
        prefix[0] = 0;
        vector<ll> postfix(n + 1);
        postfix[n] = 0;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + a[i];
        }
        for (int i = n; i >= 1; i--) {
            postfix[i - 1] = postfix[i] + a[i - 1];
        }
        priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, Comparator> queue;
        for (ll i = 0; i <= n; i++) {
            queue.push({i, (i) * (i) + (i) + postfix[i]});
        }

        ll best = -1;
        for (ll i = 0; i < n; i++) {
            pair<ll, ll> better_r = queue.top();
            if (better_r.first < i) {
                while (better_r.first < i && !queue.empty()) {
                    queue.pop();
                    better_r = queue.top();
                }
            }
            best = max(best, better_r.second + (-(i + 1) * (i + 1) + (i + 1) + prefix[i]));
        }
        cout << best << '\n';
    }
}
