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

    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    int q;
    cin >> q;
    vector<int> money(q);
    for (int i = 0; i < q; i++) cin >> money[i];

    sort(prices.begin(), prices.end());

    vector<int> results;
    for (auto current_money: money) {
        int best_result = -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (prices[mid] > current_money) {
                r = mid - 1;
            } else {
                best_result = mid;
                l = mid + 1;
            }
        }
        results.push_back(best_result + 1);
    }
    for (int i = 0; i < q; i++) {
        cout << results[i] << '\n';
    }
}
