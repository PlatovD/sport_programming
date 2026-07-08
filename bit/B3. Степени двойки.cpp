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
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;

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

    ll n, k;
    cin >> n >> k;

    priority_queue<ll> pq;
    ll power = 1;
    while (n > 0) {
        if (n & 1) pq.push(power);
        power *= 2;
        n >>= 1;
    }

    while (pq.size() != k && pq.size() < k && pq.top() != 1) {
        ll cur = pq.top();
        pq.pop();
        pq.push(cur / 2);
        pq.push(cur / 2);
    }

    if (pq.size() != k) {
        cout << "NO";
    } else {
        cout << "YES" << '\n';
        while (!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
    }
}
