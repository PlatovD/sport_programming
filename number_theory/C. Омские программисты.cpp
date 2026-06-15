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
        int a, b, x;
        cin >> a >> b >> x;
        int min_steps_cnt = abs(a - b);
        int cnt_actions = 0;
        while (x > 1 && (a > 0 || b > 0)) {
            if (a > b) {
                a /= x;
            } else {
                b /= x;
            }
            cnt_actions++;
            min_steps_cnt = min(min_steps_cnt, abs(a - b) + cnt_actions);
        }
        cout << min_steps_cnt << "\n";
    }
}
