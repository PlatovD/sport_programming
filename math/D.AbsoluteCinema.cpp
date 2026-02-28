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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> f(n);
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> f[i];

        vector<ll> diffs(n - 1);
        for (int i = 1; i < n; i++) {
            diffs[i - 1] = f[i] - f[i - 1];
        }

        int diffs_n = n - 1;
        for (int i = 1; i < diffs_n; i++) {
            a[i] = (diffs[i] - diffs[i - 1]) / 2;
        }

        a[0] = f[n - 1];
        int k = n - 2;
        for (int i = 1; i < n - 1; i++) {
            a[0] -= k-- * a[i];
        }
        a[0] /= n - 1;

        a[n - 1] = f[0];
        k = 1;
        for (int i = 1; i < n-1; i++) {
            a[n - 1] -= k++ * a[i];
        }
        a[n - 1] /= n - 1;

        for (auto el: a) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}
