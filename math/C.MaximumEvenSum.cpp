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

ll find_nechet_del(int num) {
    while (num > 1) {
        if (num % 2 == 1) return num;
        num /= 2;
    }
    return -1;
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
        ll a, b;
        cin >> a >> b;
        if (a % 2 == 1 && b % 2 == 1) {
            cout << a * b + 1 << '\n';
            continue;
        }
        if (a % 2 == 0 && b % 2 == 1) {
            cout << -1 << '\n';
            continue;
        }
        if (a % 2 == 0 && b % 2 == 0) {
            cout << a * (b / 2) + b / (b / 2) << '\n';
            continue;
        }
        if (a % 2 == 1 && b % 2 == 0) {
            if (b % 4 != 0) cout << -1 << '\n';
            else cout << a * (b / 2) + b / (b / 2) << '\n';
        }
    }
}
