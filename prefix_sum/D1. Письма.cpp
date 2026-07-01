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

    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> prefixes(n);
    prefixes[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        prefixes[i + 1] = prefixes[i] + a[i];
    }

    ll b;
    while (m--) {
        cin >> b;
        int l = 0, r = n - 1;
        int best = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (b < prefixes[mid]) {
                r = mid - 1;
            } else {
                best = mid;
                l = mid + 1;
            }
        }
        cout << best + 1 << ' ' << b - prefixes[best] + 1 << '\n';
    }
}
