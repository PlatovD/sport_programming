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
        ll res = 0;
        int n, k;
        cin >> n >> k;
        vector<int> ingots(n);
        for (auto &el: ingots) cin >> el;
        sort(ingots.begin(), ingots.end(), greater<int>());
        int taken = 0;
        int l = 0;
        int r = n - 1;
        while (taken < n && n - 1 != taken) {
            res += ingots[l];
            l++;
            n--;
            taken++;
        }
        while (ingots[r] <= 1) {
            r--;
        }
        while (l < r && k > 0) {
            if (n != taken) {
                ingots[r]--;
                res += ingots[l];
                taken++;
                l++;
                k--;
            } else if (taken == n) {
                if (k == 1) break;
                k--;
                ingots[r] -= 2;
                if (ingots[r] == 0) {
                    n++;
                    r -= 1;
                    continue;
                }
                taken++;
                n++;
                k--;
                res += ingots[l];
                l++;
            }
            if (ingots[r] == 1) r--;
        }
        if (ingots[l] > 1) {
            if (k > 0) {
                if (taken < n)
                    res += ingots[l] - 1;
                else if (ingots[l] > 2 && k > 1) res += ingots[l] - 2;
            }
        }
        cout << res << '\n';
    }
}
