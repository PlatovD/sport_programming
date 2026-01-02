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
        ll n;
        cin >> n;
        ll price = 0;
        map<ll, ll> powers;
        while (n > 0) {
            for (int i = 0; i < 10e5; i++) {
                ll current_num;
                if (powers.find(i) != powers.end()) {
                    current_num = powers[i];
                } else {
                    current_num = pow(3, i);
                    powers[i] = current_num;
                }
                if (current_num > n) {
                    current_num /= 3;
                    n -= current_num;
                    if (i > 1)
                        price += powers[i] + (i - 1) * powers[i - 2];
                    else
                        price += powers[i];
                    break;
                }
            }
        }
        cout << price << '\n';
    }
}
