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
using namespace std;

ll MOD = 1e9 + 7;

vector<vector<ll> > mul_matrix(const vector<vector<ll> > &m1, const vector<vector<ll> > &m2, ll mod) {
    vector res(m1.size(), vector<ll>(m2[0].size(), 0));
    for (int i = 0; i < m1.size(); i++) {
        for (int k = 0; k < m2.size(); k++) {
            if (m1[i][k] == 0) continue;
            for (int j = 0; j < m2[0].size(); j++) {
                res[i][j] = (res[i][j] + m1[i][k] * m2[k][j]) % mod;
            }
        }
    }
    return res;
}

vector<vector<ll> > fast_pow(vector<vector<ll> > m, ll power, ll mod) {
    int n = m.size();
    vector res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        res[i][i] = 1 % mod;
    }

    while (power > 0) {
        if (power % 2 == 1) {
            res = mul_matrix(res, m, mod);
        }
        m = mul_matrix(m, m, mod);
        power /= 2;
    }
    return res;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector g(n, vector<ll>(n, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a][b] = 1;
    }

    vector<vector<ll> > res = fast_pow(g, k, MOD);

    ll res_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res_sum = (res_sum + res[i][j]) % MOD;
        }
    }
    cout << res_sum << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}
