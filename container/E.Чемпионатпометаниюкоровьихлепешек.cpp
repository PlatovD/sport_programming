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

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int winner_length = 0;
    for (int i = 0; i < n; i++) {
        winner_length = max(v[i], winner_length);
    }

    bool was_winner = false;
    int best_result = -1;
    for (int i = 0; i < n; i++) {
        if (was_winner && i != n - 1 && v[i + 1] < v[i] && v[i] % 10 == 5)
            best_result = max(v[i], best_result);
        if (v[i] == winner_length) was_winner = true;
    }
    if (best_result == -1) {
        cout << 0 << '\n';
        return 0;
    }
    int cnt_bigger = 0;
    for (auto el: v) {
        if (el > best_result) cnt_bigger++;
    }
    cout << cnt_bigger + 1 << '\n';
}
