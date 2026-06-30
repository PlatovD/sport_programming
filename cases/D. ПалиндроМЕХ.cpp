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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) cin >> a[i];

        int first_zero_index = -1, second_zero_index = -1;
        for (int i = 0; i < 2 * n; i++) {
            if (a[i] != 0) continue;
            if (first_zero_index == -1) first_zero_index = i;
            else {
                second_zero_index = i;
                break;
            }
        }

        int best_length = 1;

        // представляю что 0 - середина палиндрома
        for (int index: {first_zero_index, second_zero_index}) {
            vector mex_checker(n + 1, false);
            mex_checker[0] = true;

            int l = index - 1, r = index + 1;
            while (l > -1 && r < 2 * n && a[l] == a[r]) {
                mex_checker[a[l]] = true;
                l--;
                r++;
            }

            for (int i = 0; i < n + 1; i++) {
                if (not mex_checker[i]) {
                    best_length = max(best_length, i);
                    break;
                }
            }
        }

        // представляю что оба 0 участвуют в последовательности
        vector mex_checker(n + 1, false);
        int l = first_zero_index, r = second_zero_index;
        bool is_good = true;
        while (l < r) {
            mex_checker[a[l]] = true;
            if (a[l] != a[r]) {
                is_good = false;
                break;
            }
            l++;
            r--;
        }
        if (l == r) {
            mex_checker[a[l]] = true;
        }

        if (is_good) {
            l = first_zero_index - 1, r = second_zero_index + 1;
            while (l > -1 && r < 2 * n && a[l] == a[r]) {
                mex_checker[a[l]] = true;
                l--;
                r++;
            }
            for (int i = 0; i < n + 1; i++) {
                if (not mex_checker[i]) {
                    best_length = max(best_length, i);
                    break;
                }
            }
        }

        cout << best_length << '\n';
    }
}
