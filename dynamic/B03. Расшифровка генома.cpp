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

vector<vector<ll> > mul_matrix(vector<vector<ll> > &m1, vector<vector<ll> > &m2, ll mod) {
    vector res(m1.size(), vector<ll>(m2[0].size(), 0));

    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m2[0].size(); j++) {
            ll x = 0;
            for (int k = 0; k < m2.size(); k++) {
                x = (x + (m1[i][k] * m2[k][j]) % mod) % mod;
            }
            res[i][j] = x;
        }
    }

    return res;
}

vector<vector<ll> > fast_pow(vector<vector<ll> > &m, ll power, ll mod) {
    vector res(m.size(), vector<ll>(m[0].size(), 0));
    for (int i = 0; i < m.size(); i++) res[i][i] = 1;

    while (power > 0) {
        if (power & 1) res = mul_matrix(res, m, mod);
        m = mul_matrix(m, m, mod);
        power >>= 1;
    }

    return res;
}

int get_index(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 26;
    }
    return -1;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector g(m, vector<ll>(m, 1));

    string p;
    while (k--) {
        cin >> p;
        int index_1 = get_index(p[1]);
        int index_2 = get_index(p[0]);
        g[index_1][index_2] = 0;
    }

    vector<vector<ll> > res_g = fast_pow(g, n - 1, MOD);
    vector start(m, vector<ll>(1, 1));

    vector<vector<ll> > res = mul_matrix(res_g, start, MOD);

    ll sum = 0;
    for (int i = 0; i < m; i++) {
        sum = (sum + res[i][0]) % MOD;
    }
    cout << sum;
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
