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

vector<ll> find_all_dividers(ll num) {
    vector<ll> divs;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            divs.push_back(i);
            if (num / i != i)divs.push_back(num / i);
        }
    }
    return divs;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> divs1 = find_all_dividers(n);
    vector<ll> divs2 = find_all_dividers(m);

    set<ll> ans;
    for (int i = 0; i < divs1.size(); i++) {
        for (int j = 0; j < divs2.size(); j++) {
            ll x = divs1[i] * divs2[j] - m;
            ll y = n - (n / (x + m)) * (m / (x + m));
            if (x > 0 && y > 0) ans.insert(x);
        }
    }
    if (ans.size() == 0) {
        cout << -1;
    } else {
        for (ll num: ans) {
            cout << num << " ";
        }
    }
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
