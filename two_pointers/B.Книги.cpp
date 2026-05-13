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

    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = 0;
    int best_num = -1;
    int current_sum = a[0];
    while (l < n && r < n) {
        if (current_sum > t) {
            if (l < r) current_sum -= a[l++];
            else {
                current_sum -= a[l++];
                r++;
                current_sum += a[r];
            }
        } else if (current_sum <= t) {
            best_num = max(r - l + 1, best_num);
            r++;
            current_sum += a[r];
        }
    }
    cout << max(best_num, 0) << endl;
}
