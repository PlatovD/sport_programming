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

vector<vector<ll> > mul_matrix(const vector<vector<ll> > &m1, const vector<vector<ll> > &m2, ll mod) {
    if (m1[0].size() != m2.size()) {
        return {{}};
    }

    vector res(m1.size(), vector<ll>(m2[0].size(), 0));
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m2[0].size(); j++) {
            for (int k = 0; k < m1[0].size(); k++) {
                res[i][j] = (res[i][j] % mod + m1[i][k] % mod * m2[k][j] % mod) % mod;
            }
        }
    }

    return res;
}

vector<vector<ll> > fast_pow(vector<vector<ll> > m, ll power, ll mod) {
    vector res(m.size(), vector<ll>(m.size(), 0));
    for (int i = 0; i < m.size(); i++) {
        res[i][i] = 1 % mod;
    }

    while (power > 0) {
        if (power & 1) {
            res = mul_matrix(res, m, mod);
        }
        m = mul_matrix(m, m, mod);
        power /= 2;
    }

    return res;
}

void solve() {
    ll n;
    cin >> n;

    vector<vector<ll> > f0 = {{1}, {0}};
    vector<vector<ll> > m = {{19, 6}, {7, 20}};

    vector<vector<ll> > res_m = fast_pow(m, n, MOD);
    vector<vector<ll> > res = mul_matrix(res_m, f0, MOD);
    cout << res[0][0] << endl;
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
