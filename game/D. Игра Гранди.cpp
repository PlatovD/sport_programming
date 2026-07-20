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
#include <unordered_set>

#define ll long long
#define ld long double
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;

int mex(set<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums.find(i) == nums.end()) {
            return i;
        }
    }
    return nums.size();
}

int dfs(int num, vector<int> &grandy) {
    if (num == 1) {
        grandy[num] = 0;
        return grandy[num];
    }

    if (grandy[num] != -1) return grandy[num];

    set<int> nums;
    for (int i = 1; i < num; i++) {
        if (num - i == i) continue;
        nums.insert(dfs(num - i, grandy) ^ dfs(i, grandy));
    }

    int cur_mex = mex(nums);
    grandy[num] = cur_mex;
    return cur_mex;
}

void solve() {
    int n;
    cin >> n;
    // n = 1e4 + 1;

    // vector grandy(n, -1);
    // for (int i = 1; i < n; i++) {
    //     if (grandy[i] != -1) continue;
    //     dfs(i, grandy);
    // }

    // for (int i = 1; i < n; i++) {
    //     if (grandy[i] == 0) {
    //         cout << i << ", ";
    //     }
    // }
    // cout << endl;
    // for (int i = 1; i < n; i++) {
    //     if (!grandy[i] == 0) {
    //         cout << i << " ";
    //     }
    // }
    // cout << endl;
    // cout << grandy[6] << '\n';
    // cout << grandy[7] << '\n';
    // cout << grandy[8] << '\n';

    // if (n % 2 == 1) {
    //     cout << "second" << '\n';
    // } else {
    //     cout << "first" << '\n';
    // }

    unordered_set nums({
        1, 2, 4, 7, 10, 20, 23, 26, 50, 53, 270, 273, 276, 282, 285, 288, 316, 334, 337, 340, 346, 359, 362, 365, 386,
        389, 392, 566, 630, 633, 636, 639, 673, 676, 682, 685, 923, 926, 929, 932, 1222
    });

    if (nums.find(n) != nums.end()) {
        cout << "second" << '\n';
    } else {
        cout << "first" << '\n';
    }
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
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

// 1 2 4 7 10 20 23 26 50 53 270 273 276 282 285 288 316 334
