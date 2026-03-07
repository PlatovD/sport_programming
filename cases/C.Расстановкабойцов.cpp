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

int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;
    if (n < k) {
        cout << "NO" << '\n';
        return 0;
    }
    if ((1 + k) * k / 2 < n) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    ll s = (1 + k) * k / 2;
    ll left = 0;
    ll right = left + k - 1;
    ll level_required = 1;
    ll next_level_required = 2;
    while (n > 0) {
        n--;
        if (s - (right - left + 1) >= n) {
            cout << left << ' ' << right << '\n';
            s -= right - left + 1;
            next_level_required--;
        } else {
            cout << left << ' ' << left << '\n';
            s -= 1;
        }
        level_required--;
        if (level_required == 0) {
            level_required = next_level_required;
            left++;
            next_level_required++;
        }
    }
}
