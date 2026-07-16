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
        return {};
    }
    vector res(m1.size(), vector<ll>(m2[0].size(), 0));
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m2[0].size(); j++) {
            for (int k = 0; k < m1[0].size(); k++) {
                res[i][j] += (m1[i][k] * m2[k][j] % mod + mod) % mod;
            }
        }
    }
    return res;
}

vector<vector<ll> > fast_pow(vector<vector<ll> > matrix, ll power, ll mod) {
    if (power == 0) {
        vector res(matrix.size(), vector<ll>(matrix.size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            res[i][i] = 1;
        }
        return res;
    }
    if (power == 1) return matrix;
    if (power % 2 == 0) {
        vector<vector<ll> > res = fast_pow(matrix, power / 2, mod);
        return mul_matrix(res, res, mod);
    }
    return mul_matrix(matrix, fast_pow(matrix, power - 1, mod), mod);
}

void solve() {
    ll n;
    cin >> n;

    vector<vector<ll> > f0 = {{1}, {0}};
    vector<vector<ll> > m = {{1, 1}, {1, 0}};
    vector<vector<ll> > res_m = fast_pow(m, n, MOD);
    vector<vector<ll> > res = mul_matrix(res_m, f0, MOD);
    cout << res[1][0];
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
