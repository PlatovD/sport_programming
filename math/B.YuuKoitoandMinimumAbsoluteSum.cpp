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
        vector<int> arr(n);
        for (auto &el: arr) cin >> el;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                if (i == 0) {
                    arr[i] = max(0, arr[n - 1]);
                } else if (i == n - 1) {
                    arr[i] = arr[0];
                } else {
                    arr[i] = 0;
                }
            }
        }
        cout << abs(arr[0] - arr[n - 1]) << '\n';
        for (const auto num: arr) {
            cout << num << ' ';
        }
        cout << '\n';
    }
}
