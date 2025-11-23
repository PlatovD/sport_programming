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
    for (int q = 0; q < t; q++) {
        int n;
        cin >> n;
        vector<int> tree(n);
        for (auto &el: tree) cin >> el;

        int is_min_strick = false;
        int strick_min_val = INT32_MAX;
        int min_val = tree[0];
        for (int i = 1; i < n; i++) {
            if (tree[i] < min_val) {
                is_min_strick = true;
                strick_min_val = min(strick_min_val, tree[i]);
            } else {
                is_min_strick = false;
                min_val = min(strick_min_val, min_val);
            }
        }

        if (is_min_strick) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
    }
}
