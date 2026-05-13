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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt_0 = a[0] == 0 ? 1 : 0;
    int best_len = 0;
    pair<int, int> best_indexes{-1, -1};
    int l = 0, r = 0;
    while (l < n && r < n) {
        if (cnt_0 > k) {
            while (cnt_0 > k) {
                cnt_0 -= a[l] == 0 ? 1 : 0;
                l++;
            }
        }
        if (best_len < r - l + 1) {
            best_len = r - l + 1;
            best_indexes = {l, r};
        }
        r++;
        if (a[r] == 0) cnt_0++;
    }
    cout << best_len << '\n';
    for (int i = 0; i < n; i++) {
        if (i >= best_indexes.first && i <= best_indexes.second) {
            cout << 1 << ' ';
        } else {
            cout << a[i] << ' ';
        }
    }
}
