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

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> diff(n);
    diff[0] = a[0];
    for (int i = 1; i < n; i++) {
        diff[i] = a[i] - a[i - 1];
    }

    int q;
    cin >> q;

    int l, r, d;
    while (q--) {
        cin >> l >> r >> d;
        l--;
        r--;
        diff[l] += d;
        if (r + 1 < n)
            diff[r + 1] -= d;
    }

    vector<ll> prefixes(n + 1);
    prefixes[0] = diff[0];
    for (int i = 1; i < n + 1; i++) {
        prefixes[i] = prefixes[i - 1] + diff[i];
    }
    for (int i = 0; i < n; i++) {
        cout << prefixes[i] << ' ';
    }
}
