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

bool is_number_palindrome(ll num) {
    string res = to_string(num);
    int l = 0, r = res.size() - 1;
    while (l < r) {
        if (res[l] != res[r]) return false;
        l++;
        r--;
    }
    return true;
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

    map<ll, ll> for_every_remainder;

    for (ll i = 0; i < 12; i++) {
        ll num = i;
        while (!is_number_palindrome(num)) {
            num += 12;
        }
        for_every_remainder[i] = num;
    }

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        // для каждого начального остатка n от деления на 12 я найду ближайший палиндром, при помощи добавления к этому остатку 12 по кругу. Дальше просто смотреть, получается ли уместить
        ll reminder = n % 12;
        ll a = for_every_remainder[reminder];
        ll b = n - a;
        if (b < 0) {
            cout << -1 << '\n';
        } else {
            cout << a << ' ' << b << '\n';
        }
    }
}
