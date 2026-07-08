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

bool is_power_of_2(ll num) {
    return (num - 1 & num) == 0 && num > 0;
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
        vector<ll> res;
        ll stop_i = n - 1;
        for (int i = n - 1; i > -1; i--) {
            res.push_back(i);
            if (is_power_of_2(i)) {
                stop_i = i;
                break;
            }
        }
        for (int i = 0; i < stop_i; i++) {
            res.push_back(i);
        }
        for (auto num: res) cout << num << " ";
        cout << endl;
    }
}
