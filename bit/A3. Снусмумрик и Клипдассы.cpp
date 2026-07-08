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
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;

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

    int q;
    cin >> q;
    vector<ll> ranks(31, 1);
    while (q--) {
        ll n;
        cin >> n;
        int current_rank = 0;
        while (n > 0) {
            if (n & 1) ranks[current_rank] = ranks[current_rank] == 0 ? 1 : 0;
            n >>= 1;
            current_rank++;
        }
    }
    int cnt_zero = 0;
    for (int i = 1; i < 31; i++) {
        if (ranks[i] == 0) cnt_zero++;
    }
    cout << cnt_zero;
}
