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


int max_divider(int x, int y) {
    int max_div = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            if (y % i == 0) {
                max_div = max(i, max_div);
            }
            if (y % (x / i) == 0) {
                max_div = max(x / i, max_div);
            }
        }
    }
    if (y % x == 0) {
        max_div = max(x, max_div);
    }
    return max_div;
}

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

        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];

        int res = 0;
        int l = 0;
        int r = 1;
        while (r < n) {
            int diff = abs(p[r] - p[l]);
            int max_div = max_divider(min(p[l], p[r]), max(p[l], p[r]));
            if (max_div == diff) res++;
            l++;
            r++;
        }
        cout << res << "\n";
    }
}
