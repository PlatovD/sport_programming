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


void solve() {
    int n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll to = 8 * 1e6;
    vector is_simple(to, true);
    is_simple[0] = false;
    is_simple[1] = false;
    vector<ll> simples;
    vector<ll> counts(to, 0);
    for (ll i = 2; i < to; i++) {
        if (!is_simple[i]) continue;
        simples.push_back(i);
        for (ll j = i * i; j < to; j += i) {
            is_simple[j] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        int current_simple_index = 0;
        while (current_simple_index < simples.size() && simples[current_simple_index] * simples[current_simple_index] <=
               a[i]) {
            {
                if (a[i] % simples[current_simple_index] == 0) {
                    counts[simples[current_simple_index]]++;
                    while (a[i] % simples[current_simple_index] == 0)
                        a[i] /= simples[current_simple_index];
                }
                current_simple_index++;
            }
        }

        if (a[i] > 1 && a[i] < to) {
            counts[a[i]]++;
        }
    }

    ll best_simple = 2;
    ll teams_unhappy = counts[best_simple];
    int simple_pointer = 1;
    while (simple_pointer < simples.size() && simples[simple_pointer] <= x && teams_unhappy > 0) {
        if (counts[simples[simple_pointer]] < teams_unhappy) {
            best_simple = simples[simple_pointer];
            teams_unhappy = counts[simples[simple_pointer]];
        }
        simple_pointer++;
    }
    cout << best_simple;
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

    solve();
}
