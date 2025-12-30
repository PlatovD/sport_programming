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
        int a, b;
        cin >> a >> b;
        int first_cnt = 0;
        int step = 0;
        int level = 1;
        int odd = a;
        int even = b;
        while (true) {
            if (step % 2 == 0) {
                if (level > odd) break;
                odd -= level;
                first_cnt++;
            } else {
                if (level > even) break;
                even -= level;
                first_cnt++;
            }
            level <<= 1;
            step++;
        }
        step = 0;
        int second_cnt = 0;
        level = 1;
        odd = b;
        even = a;
        while (true) {
            if (step % 2 == 0) {
                if (level > odd) break;
                odd -= level;
                second_cnt++;
            } else {
                if (level > even) break;
                even -= level;
                second_cnt++;
            }
            level <<= 1;
            step++;
        }
        cout << max(first_cnt, second_cnt) << '\n';
    }
}
