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

    int n;
    cin >> n;

    vector<ll> mount;

    ll num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> num;
            mount.push_back(num);
        }
    }

    vector<ll> dp(mount.size(), INT64_MIN);
    dp[0] = mount[0];
    int current_index = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= i; j++) {
            int left_index = current_index + (i + 1);
            int right_index = current_index + (i + 1) + 1;
            if (left_index < dp.size()) {
                dp[left_index] = max(dp[left_index], dp[current_index] + mount[left_index]);
            }
            if (right_index < dp.size()) {
                dp[right_index] = max(dp[right_index], dp[current_index] + mount[right_index]);
            }
            current_index++;
        }
    }

    ll ma = INT64_MIN;
    for (int i = (int) dp.size() - 1; i >= (int) dp.size() - n; i--) {
        ma = max(dp[i], ma);
    }
    cout << ma;
}
