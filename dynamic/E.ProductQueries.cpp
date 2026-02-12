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

int find_dividers(int num, vector<int> &reach) {
    int min_els = INT32_MAX;
    for (int i = 2; num >= i * i; i++) {
        if (num % i == 0) {
            int first_divider = reach[i];
            int second_divider = reach[num / i];
            if (first_divider != -1 && second_divider != -1) {
                min_els = min(min_els, first_divider + second_divider);
            }
        }
    }
    return min_els == INT32_MAX ? -1 : min_els;
}

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
        vector<int> numbers(n);
        for (auto &el: numbers) cin >> el;
        vector reach(n + 1, -1);
        for (int i = 0; i < n; i++) {
            if (numbers[i] == 1) {
                reach[1] = 1;
                continue;
            }
            int can_reach = numbers[i];
            reach[can_reach] = 1;
        }

        for (int i = 1; i <= n; i++) {
            if (reach[i] != -1) {
                cout << reach[i] << ' ';
            } else {
                int min_els = find_dividers(i, reach);
                reach[i] = min_els;
                cout << reach[i] << ' ';
            }
        }
        cout << '\n';
    }
}
