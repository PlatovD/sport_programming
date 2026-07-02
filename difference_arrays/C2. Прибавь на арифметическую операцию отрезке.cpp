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

    vector<ll> diff_diff(n);
    diff_diff[0] = diff[0];
    for (int i = 1; i < n; i++) {
        diff_diff[i] = diff[i] - diff[i - 1];
    }

    int q;
    cin >> q;
    ll l, r, d;
    while (q--) {
        cin >> l >> r >> d;
        l--;
        r--;
        diff_diff[l] += d;
        if (r + 1 < n)
            diff_diff[r + 1] -= (r - l + 1) * d + d;
        if (r + 2 < n)
            diff_diff[r + 2] += (r - l + 1) * d;
    }

    // восстанавливаю
    vector<ll> prefix_diff_diff(n);
    prefix_diff_diff[0] = diff_diff[0];
    for (int i = 1; i < n; i++) {
        prefix_diff_diff[i] = prefix_diff_diff[i - 1] + diff_diff[i];
    }

    vector<ll> result(n);
    result[0] = prefix_diff_diff[0];
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] + prefix_diff_diff[i];
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
}
