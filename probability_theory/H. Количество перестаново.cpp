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
    ll mod = 998244353ll;

    vector<ll> factorial(3 * 1e5 + 1);
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i <= 3 * 1e5; i++) {
        factorial[i] = factorial[i - 1] * i % mod;
    }


    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<pair<int, int> > ab(n);
    int a_i, b_i;
    for (int i = 0; i < n; i++) {
        cin >> a_i >> b_i;
        a[i] = a_i;
        b[i] = b_i;
        ab[i] = {a_i, b_i};
    }

    ll total_permutations = factorial[n];

    unordered_map<int, int> counts_a;
    for (int i = 0; i < n; i++) {
        counts_a[a[i]]++;
    }

    unordered_map<int, int> counts_b;
    for (int i = 0; i < n; i++) {
        counts_b[b[i]]++;
    }

    ll A = 1;
    for (auto [num,cnt]: counts_a) {
        A = A * factorial[cnt] % mod;
    }

    ll B = 1;
    for (auto [num,cnt]: counts_b) {
        B = B * factorial[cnt] % mod;
    }

    total_permutations = (total_permutations - A + mod) % mod;
    total_permutations = (total_permutations - B + mod) % mod;

    sort(ab.begin(), ab.end());
    bool bad = false;
    for (int i = 1; i < n; i++) {
        if (ab[i].second < ab[i - 1].second) {
            bad = true;
            break;
        }
    }
    if (!bad) {
        ll A_and_B = 1;
        ll cnt = 1;
        for (int i = 1; i < n; i++) {
            if (ab[i - 1] == ab[i]) {
                cnt++;
            } else {
                A_and_B = A_and_B * factorial[cnt] % mod;
                cnt = 1;
            }
        }
        A_and_B = A_and_B * factorial[cnt] % mod;

        total_permutations = (total_permutations + A_and_B) % mod;
    }

    cout << (total_permutations % mod + mod) % mod << '\n';
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
