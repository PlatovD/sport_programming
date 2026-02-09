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

class Triple {
public:
    ll a;
    ll b;
    ll c;

    Triple(long long a, long long b, long long c)
        : a(a),
          b(b),
          c(c) {
    }

    Triple() = default;
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
    while (t--) {
        ll n, x;
        cin >> n >> x;
        vector<Triple> jumps(n);
        ll a, b, c;
        for (int i = 0; i < n; i++) {
            cin >> a >> b >> c;
            jumps[i] = Triple(a, b, c);
        }

        // здесь подсчитаю возможность прыжка без откатов
        ll initial_jump = 0;
        for (int i = 0; i < n; i++) {
            initial_jump += jumps[i].a * (jumps[i].b - 1);
        }
        if (initial_jump >= x) {
            cout << 0 << '\n';
            continue;
        }
        x -= initial_jump;
        // тут уже надо выбирать оптимальную стратегию для минимизации откатов
        ll optimal_a = 0, optimal_b = 0, optimal_c = 0, optimal_profit_by_step = -1;
        for (Triple tr: jumps) {
            if (tr.a * tr.b - tr.c > optimal_profit_by_step) {
                optimal_profit_by_step = tr.a * tr.b - tr.c;
                optimal_a = tr.a;
                optimal_b = tr.b;
                optimal_c = tr.c;
            }

            if (tr.a * tr.b - tr.c == optimal_profit_by_step && tr.a * (tr.b - 1) > optimal_a * (optimal_b - 1)) {
                optimal_profit_by_step = tr.a * tr.b - tr.c;
                optimal_a = tr.a;
                optimal_b = tr.b;
                optimal_c = tr.c;
            }
        }
        if (optimal_profit_by_step <= 0) {
            cout << -1 << '\n';
            continue;
        }


        ll steps = x / optimal_profit_by_step;
        x -= steps * optimal_profit_by_step;
        if (x <= 0)
            cout << steps << '\n';
        else
            cout << steps + 1 << '\n';
    }
}
