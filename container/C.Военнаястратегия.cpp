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
        ll n, m, k;
        cin >> n >> m >> k;

        if (k - 1 < n - k) k = n + 1 - k;
        int a = 0, b = 0;
        while (true) {
            if (b < n - k && a + (b + 1) + max(a, b + 1) - 1 <= m)++b;
            if (a < k - 1 && (a + 1) + b + max(a + 1, b) - 1 <= m)++a;
            else break;
        }
        cout << a + b + 1 << '\n';
    }
}
