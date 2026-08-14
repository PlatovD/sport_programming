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


void solve() {
    int n;
    cin >> n;

    vector<vector<int> > a;
    vector index(n, 0);
    vector<int> res;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> nums(m);
        for (int j = m - 1; j >= 0; j--) {
            cin >> nums[j];
        }
        a.push_back(nums);
    }

    vector pretend(n, true);
    int current_combo_size = 0;
    for (int i = 0; i < n; i++) {
        int min_val, cnt_min_value, index_min_value;
        for (auto cur_index: index) {

        }
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
