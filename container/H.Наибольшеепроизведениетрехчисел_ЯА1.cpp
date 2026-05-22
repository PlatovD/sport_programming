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
        next_char = cin.get();
        if (next_char == '\n') break;
        cin.unget();
    }
    int n = v.size();

    sort(v.begin(), v.end());
    ll pos_pos_pos = v[n - 1] * v[n - 2] * v[n - 3];
    ll pos_neg_neg = v[n - 1] * v[0] * v[1];
    if (pos_pos_pos > pos_neg_neg) {
        cout << v[n - 1] << ' ' << v[n - 2] << ' ' << v[n - 3];
    } else {
        cout << v[n - 1] << ' ' << v[0] << ' ' << v[1];
    }
}
