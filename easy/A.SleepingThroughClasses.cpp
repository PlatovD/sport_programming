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
    for (int q = 0; q < t; q++) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int last_to_sleep = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                last_to_sleep = k;
            } else {
                if (last_to_sleep == 0) {
                    cnt++;
                } else
                    last_to_sleep--;
            }
        }
        cout << cnt << '\n';
    }
}
