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

    ll a, b;
    cin >> a >> b;

    set<ll> divs;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            divs.insert(i);
            divs.insert(a / i);
        }
    }
    divs.insert(1);
    divs.insert(a);

    ll best = 0;
    for (auto num: divs) {
        if (num < 3) continue;
        if (b % num == 0) {
            best = num;
            break;
        }
    }

    if (best) {
        cout << a / best + b / best << endl;
    } else {
        cout << 0 << endl;
    }
}
