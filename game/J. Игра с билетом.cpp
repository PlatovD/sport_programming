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
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;


void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    int m = n / 2;
    ll sum_left = 0, sum_right = 0;
    ll questions_left = 0, questions_right = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (i < m) questions_left++;
            else questions_right++;
            continue;
        }
        if (i < m) {
            sum_left += s[i] - '0';
        } else {
            sum_right += s[i] - '0';
        }
    }

    ll diff = abs(sum_right - sum_left);
    ll diff_questions = abs(questions_right - questions_left);
    if (diff_questions == 0) {
        cout << (diff == 0 ? "Bicarp" : "Monocarp");
    } else {
        if (questions_left > questions_right) {
            if (sum_right - sum_left == 9 * diff_questions / 2) {
                cout << "Bicarp";
            } else {
                cout << "Monocarp";
            }
        } else {
            if (sum_left - sum_right == 9 * diff_questions / 2) {
                cout << "Bicarp";
            } else {
                cout << "Monocarp";
            }
        }
    }
}

int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    solve();
}
