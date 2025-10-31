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

int get(int num, vector<int> &simple, vector<int> &dp) {
    int initial = num;
    int m = 0;
    for (int i = 2; i * i <= num; i++) {
        while (num % i == 0) {
            m = max(m, dp[simple[i]]);
            simple[i] = initial;
            num /= i;
        }
    }
    if (num != 1) {
        m = max(m, dp[simple[num]]);
        simple[num] = initial;
    }
    return m;
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &el: arr) cin >> el;
    vector dp(1e5 + 1, 0);
    dp[0] = 0;
    vector simple(1e5 + 1, 0);
    for (int i = 0; i < n; i++) {
        dp[arr[i]] = max(dp[arr[i]], get(arr[i], simple, dp) + 1);
    }
    int m = -1;
    for (int i = 0; i < 1e5 + 1; i++) {
        m = max(m, dp[i]);
    }
    cout << m;
}
