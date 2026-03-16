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
        for (int i = 0; i < n; i++) cin >> nums[i];

        int index = 1;
        bool is_bad = false;
        while (index < n - 1) {
            nums[index] -= nums[index - 1] * 2;
            nums[index + 1] -= nums[index - 1];
            nums[index - 1] = 0;
            if (nums[index] < 0 || nums[index - 1] < 0 || nums[index + 1] < 0) {
                is_bad = true;
                break;
            }
            index++;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                is_bad = true;
                break;
            }
        }
        if (is_bad || nums[n - 1] != 0) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
}
