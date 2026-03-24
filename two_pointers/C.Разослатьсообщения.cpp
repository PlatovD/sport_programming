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
        ll n, f, a, b;
        cin >> n >> f >> a >> b;
        vector<ll> m(n + 1);
        m[0] = 0;
        for (int i = 1; i < n + 1; i++) cin >> m[i];

        int l = 0;
        int r = 1;
        bool is_bad = false;
        while (r < n + 1) {
            f -= min((m[r] - m[l]) * a, b);
            if (f <= 0) {
                is_bad = true;
                break;
            }
            l++;
            r++;
        }
        if (is_bad) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
}
