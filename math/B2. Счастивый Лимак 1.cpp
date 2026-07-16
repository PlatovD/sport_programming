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

vector<vector<double> > mul_matrix(const vector<vector<double> > &m1, const vector<vector<double> > &m2) {
    if (m1.size() != m2[0].size()) {
        return {};
    }

    vector res(m1.size(), vector<double>(m2[0].size(), 0));
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m2[0].size(); j++) {
            for (int k = 0; k < m1[0].size(); k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return res;
}

vector<vector<double> > fast_pow(vector<vector<double> > m, ll power) {
    if (power == 0) {
        vector res(m.size(), vector<double>(m.size(), 0));
        for (int i = 0; i < m.size(); i++) {
            res[i][i] = 1;
        }
        return res;
    }
    if (power == 1) return m;
    if (power % 2 == 0) {
        vector<vector<double> > res = fast_pow(m, power / 2);
        return mul_matrix(res, res);
    }
    return mul_matrix(m, fast_pow(m, power - 1));
}

void solve() {
    ll n;
    double p;
    cin >> n;
    cin >> p;

    vector<vector<double> > start = {{1}, {0}};
    vector<vector<double> > m = {{1 - p, p}, {p, 1 - p}};
    vector<vector<double> > res_m = fast_pow(m, n);
    vector<vector<double> > res = mul_matrix(start, res_m);
    cout << res[0][0];
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
