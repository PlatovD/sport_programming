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
    ll num;
    cin >> num;
    ll my_num = 2;
    ll prev = 2;
    if (num == 1) {
        cout << "YES" << '\n';
        cout << 3 << ' ' << 2 << '\n';
        return 0;
    }
    while (my_num < num) {
        prev = num;
        my_num *= 2;
    }
    my_num /= 2;
    if (my_num < 0) my_num = prev;
    ll between = my_num ^ num;
    if (between > 1e18 || between < 0 || my_num > 1e18 || my_num < 0 || (my_num ^ between) != num) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << '\n';
    cout << between << ' ' << my_num << '\n';
}
