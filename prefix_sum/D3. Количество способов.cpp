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
    for (int i = 0; i < n; i++)cin >> a[i];

    map<ll, ll> prefixes;
    vector<ll> postfixes(n);
    postfixes[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        postfixes[i] = a[i + 1] + postfixes[i + 1];
    }


    ll res = 0;
    ll current_sum = a[0];
    prefixes[current_sum]++;
    for (int i = 1; i < n - 1; i++) {
        current_sum += a[i];
        if (current_sum % 2 == 0 && postfixes[i] == current_sum / 2) {
            res += prefixes[current_sum / 2];
        }
        prefixes[current_sum] += 1;
    }
    cout << res << '\n';
}
