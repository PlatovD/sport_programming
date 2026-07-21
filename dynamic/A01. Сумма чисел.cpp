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
            for (int k = 0; k < m1[i].size(); k++) {
                if (k % 7 == 0) x %= mod;
                x += m1[i][k] * m2[k][j];
            }
            res[i][j] = x % mod;
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
    ll n;
    cin >> n;

    vector<vector<ll> > m = {{1, 1, 0}, {1, 0, 0}, {1, 1, 1}};
    vector<vector<ll> > start = {{1}, {0}, {1}};

    vector<vector<ll> > m_res = fast_pow(m, n - 1, MOD);
    vector<vector<ll> > res = mul_matrix(m_res, start, MOD);
    cout << res[2][0];
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
