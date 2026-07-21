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

int cnt_xor_bits(ll n1, ll n2) {
    ll n_xor = n1 ^ n2;
    ll cnt = 0;
    while (n_xor > 0) {
        cnt += n_xor & 1;
        n_xor >>= 1;
    }
    return (int) cnt;
}

vector<vector<ll> > mul_matrix(vector<vector<ll> > &m1, vector<vector<ll> > &m2, ll mod) {
    vector res(m1.size(), vector<ll>(m2[0].size(), 0));

    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m2[0].size(); j++) {
            ll x = 0;
            for (int k = 0; k < m2.size(); k++) {
                x = (x + m1[i][k] * m2[k][j] % mod) % mod;
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

void solve() {
    ll n, k;
    cin >> n >> k;

    vector g(n, vector<ll>(n, 0));
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int xor_bits = cnt_xor_bits(a[i], a[j]);
            if (xor_bits % 3 == 0) {
                g[i][j] = 1;
                g[j][i] = 1;
            }
        }
    }

    vector<vector<ll> > res_m = fast_pow(g, k-1, MOD);
    vector start(n, vector<ll>(1, 1));


    vector<vector<ll> > res = mul_matrix(res_m, start, MOD);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
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
