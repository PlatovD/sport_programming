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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &el: nums) cin >> el;

        int l = -1;
        int r = 1;
        int best_profit = 0;
        for (int i = 0; i < n; i++) {
            int current = 0;
            int will_be = 0;
            if (l >= 0) current += abs(nums[l] - nums[i]);
            if (r < n) current += abs(nums[i] - nums[r]);
            if (l >= 0 && r < n) will_be = abs(nums[l] - nums[r]);
            if (current - will_be > best_profit) {
                best_profit = current - will_be;
            }
            l++;
            r++;
        }

        int cur_sum = 0;
        for (int i = 1; i < n; i++) {
            cur_sum += abs(nums[i - 1] - nums[i]);
        }
        cout << cur_sum - best_profit << '\n';
    }
}