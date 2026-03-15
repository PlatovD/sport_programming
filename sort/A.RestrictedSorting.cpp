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
        vector<ll> nums(n);
        vector<ll> sorted_nums(n);
        ll last = INT64_MIN;
        bool is_sorted = true;
        for (ll i = 0; i < n; i++) {
            cin >> nums[i];
            sorted_nums[i] = nums[i];
            if (last > nums[i]) is_sorted = false;
            last = nums[i];
        }
        if (is_sorted) {
            cout << -1 << '\n';
            continue;
        }

        sort(sorted_nums.begin(), sorted_nums.end());

        ll min_val = INT64_MAX;
        ll max_val = INT64_MIN;
        for (ll i = 0; i < n; i++) {
            min_val = min(min_val, nums[i]);
            max_val = max(max_val, nums[i]);
        }
        ll min_diff = INT64_MAX;
        for (ll i = 0; i < n; i++) {
            if (nums[i] == sorted_nums[i]) continue;
            min_diff = min(min_diff, max(abs(nums[i] - min_val), abs(nums[i] - max_val)));
        }
        cout << min_diff << '\n';
    }
}
