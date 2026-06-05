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
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());

        vector<int> cnt_lower(n);
        int combo = 1;
        cnt_lower[0] = 0;
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i - 1]) {
                cnt_lower[i] = cnt_lower[i - 1] + combo;
                combo = 1;
            } else {
                cnt_lower[i] = cnt_lower[i - 1];
                combo++;
            }
        }

        combo = 1;
        vector<int> cnt_greater(n);
        cnt_greater[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] < v[i + 1]) {
                cnt_greater[i] = cnt_greater[i + 1] + combo;
                combo = 1;
            } else {
                cnt_greater[i] = cnt_greater[i + 1];
                combo++;
            }
        }

        int min_calls = INT32_MAX;
        for (int i = 0; i < n; i++) {
            min_calls = min(min_calls, min(cnt_lower[i], cnt_greater[i]) + abs(cnt_lower[i] - cnt_greater[i]));
        }
        cout << min_calls << endl;
    }
}
