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
    vector<ll> positions(n);
    for (int i = 0; i < n; i++) cin >> positions[i];

    sort(positions.begin(), positions.end());

    // буду хранить минимальную стоимость для того, чтобы первые i гвоздиков были покрыты нитками
    vector<ll> dp(n, INT32_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        // из iого гвоздика я могу покрыть либо i-1 гвоздик, либо i гвоздиков с соответствующей стоимостью
        dp[i] = min(dp[i], dp[i - 1] + positions[i] - positions[i - 1]);
        if (i + 1 < n && i != 1) {
            dp[i + 1] = min(dp[i + 1], dp[i - 1] + positions[i + 1] - positions[i]);
        }
    }
    cout << dp[n - 1] << endl;
}
