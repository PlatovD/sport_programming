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

ll find_min_simple_divider(ll num) {
    for (ll i = 2; i * i <= num; i++) {
        if (num % i == 0) return i;
    }
    return num;
}

int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll cnt = 0;
    if (n % 2 == 0) {
        cout << n / 2 << '\n';
        return 0;
    }
    while (n % 2 != 0) {
        cnt++;
        n -= find_min_simple_divider(n);
    }
    cnt += n / 2;
    cout << cnt << '\n';
}
