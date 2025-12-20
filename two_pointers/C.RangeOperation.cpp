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
        vector<int> a(n);
        for (auto &el: a) cin >> el;

        int max_sum = 0;
        for (int val: a) max_sum += val;
        int l = 0;
        int r = n - 1;
        int outer_sum = 0;
        while (r >= l) {
            max_sum = max(max_sum, outer_sum + (r + l + 2) * (r - l + 1));
            if (a[l] >= a[r]) {
                outer_sum += a[l];
                l++;
            } else {
                outer_sum += a[r];
                r--;
            }
        }
        cout << max_sum << '\n';
    }
}
