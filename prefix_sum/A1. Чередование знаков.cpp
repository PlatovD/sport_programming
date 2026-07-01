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
    int cnt_changes_first_try = 0, cnt_changes_second_try = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (a[i] < 0)cnt_changes_first_try++;
        } else {
            if (a[i] > 0) cnt_changes_first_try++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            if (a[i] < 0) cnt_changes_second_try++;
        } else {
            if (a[i] > 0) cnt_changes_second_try++;
        }
    }

    cout << min(cnt_changes_first_try, cnt_changes_second_try) << endl;
}
