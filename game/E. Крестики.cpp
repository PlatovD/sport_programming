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
#define ld long double
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;

vector grandy(5 * 1e3 + 1, -1);

int mex(set<int> nums) {
    for (int i = 0; i <= nums.size(); i++) {
        if (nums.find(i) != nums.end()) continue;
        return i;
    }
    return 0;
}

int dfs(int num, vector<int> &grandy) {
    if (num <= 0) return 0;

    if (grandy[num] != -1)
        return grandy[num];

    set<int> other_grandy;

    for (int i = 1; i <= num; i++) {
        int left_part = max(0, i - 2);
        int right_part = max(0, num - i - 1);

        other_grandy.insert(dfs(left_part, grandy) ^ dfs(right_part, grandy));
    }

    int cur_mex = mex(other_grandy);
    grandy[num] = cur_mex;
    return cur_mex;
}

void solve() {
    int n;
    cin >> n;

    if (grandy[n] != 0) {
        cout << "first" << '\n';
    } else {
        cout << "second" << '\n';
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

    grandy[0] = 0;
    for (int i = 0; i < 5 * 1e3 + 1; i++) {
        if (grandy[i] != -1) continue;
        dfs(i, grandy);
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
