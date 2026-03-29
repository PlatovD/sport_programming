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
        int n;
        cin >> n;
        vector has_ball(n, false);
        string s;
        cin >> s;
        int index = 0;

        while (true) {
            if (has_ball[index] == true) break;
            has_ball[index] = true;
            if (s[index] == 'L') index--;
            else index++;
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (has_ball[i]) sum++;
        }
        cout << sum << '\n';
    }
}
