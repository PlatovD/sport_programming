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

    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;

    int current_pos = 0;
    int cnt_updates = 0;
    while (current_pos != n - 1) {
        int best_next_pos = -1;
        for (int i = 1; i <= d; i++) {
            if (s[current_pos + i] == '1') {
                best_next_pos = current_pos + i;
            }
        }
        if (best_next_pos == -1) {
            cout << -1;
            return 0;
        }
        current_pos = best_next_pos;
        cnt_updates++;
    }
    cout << cnt_updates << endl;
}
