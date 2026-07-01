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
    bool was_0 = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) was_0 = true;
    }

    if (was_0) {
        cout << "Yes" << '\n';
        return 0;
    }

    ll current_prefix = 0;
    set<ll> prefixes;
    for (int i = 0; i < n; i++) {
        current_prefix += a[i];
        if (prefixes.find(current_prefix) != prefixes.end()) {
            cout << "Yes" << '\n';
            return 0;
        }
        prefixes.insert(current_prefix);
    }
    cout << "No" << '\n';
}
