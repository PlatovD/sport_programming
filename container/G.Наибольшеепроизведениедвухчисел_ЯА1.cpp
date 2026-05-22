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
#include<set>
#include <cstdint>
#include <set>
#include <algorithm>
#include <random>
#include <iomanip>
#include <assert.h>

#define ll long long
using namespace std;

// шаблон
int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    ll x;
    vector<ll> v;
    char next_char;
    while (cin >> x) {
        v.push_back(x);
        nextChar = cin.get();
        if (nextChar == '\n') break;
        cin.unget();
    }
    int n = v.size();
    sort(v.begin(), v.end());
    if (v[0] * v[1] > v[n - 1] * v[n - 2]) {
        cout << min(v[0], v[1]) << ' ' << max(v[0], v[1]) << '\n';
    } else {
        cout << min(v[n - 1], v[n - 2]) << ' ' << max(v[n - 1], v[n - 2]) << '\n';
    }
}
