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
        ll s, k, m;
        cin >> s >> k >> m;
        ll top_even_steps = s;
        ll top_odd_steps = min(s, k);
        ll cnt_replaces = m / k;
        if (cnt_replaces % 2 == 0) {
            cout << max(0ll, top_even_steps - (m - cnt_replaces * k)) << '\n';
        } else {
            cout << max(0ll, top_odd_steps - (m - cnt_replaces * k)) << '\n';
        }
    }
}
