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
        ll n;
        cin >> n;
        vector<ll> head(n);
        vector<ll> body(n);
        vector<ll> legs(n);

        for (auto &el: head) cin >> el;
        for (auto &el: body) cin >> el;
        for (auto &el: legs) cin >> el;

        ll good_head_body = 0;
        for (int start_head = 0; start_head < n; start_head++) {
            bool is_good = true;
            for (int i = 0; i < n; i++) {
                if (head[(start_head + i) % n] >= body[i]) {
                    is_good = false;
                    break;
                }
            }
            if (is_good)
                good_head_body++;
        }

        ll good_body_legs = 0;
        for (int start_body = 0; start_body < n; start_body++) {
            bool is_good = true;
            for (int i = 0; i < n; i++) {
                if (body[(start_body + i) % n] >= legs[i]) {
                    is_good = false;
                    break;
                }
            }
            if (is_good)
                good_body_legs++;
        }
        cout << good_head_body * n * good_body_legs << '\n';
    }
}
