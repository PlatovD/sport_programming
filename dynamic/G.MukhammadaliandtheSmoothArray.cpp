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

ll count_price_make_lower_all_before(int index, vector<int> &arr, vector<int> &prices) {
    ll price = 0;
    for (int i = index - 1; i > -1; i--) {
        if (arr[i] > arr[index]) price += prices[i];
    }
    return price;
}


int main() {
    // #if defined _DEBUG
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &el: arr) cin >> el;
        vector<int> price(n);
        for (auto &el: price) cin >> el;
        vector<ll> dp(n);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                ll make_lower = count_price_make_lower_all_before(i, arr, price);
                if (make_lower <= dp[i-1] + price[i]) {
                    dp[i] = make_lower;
                } else {
                    dp[i] = dp[i - 1] + price[i];
                    arr[i] = arr[i - 1];
                }
            } else {
                dp[i] = dp[i - 1];
            }
        }
        cout << dp[n - 1] << '\n';
    }
}