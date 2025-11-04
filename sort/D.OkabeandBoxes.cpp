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

bool comp(int a, int b) {
    return a > b;
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

    int n;
    cin >> n;
    string s;
    stack<int> added;
    int num;
    int cnt_to_check = 0;
    int cnt = 0;
    int cur_num = 1;
    for (int i = 0; i < 2 * n; i++) {
        cin >> s;
        if (s == "remove") {
            if (cnt_to_check != 0) {
                if (added.top() != cur_num) {
                    cnt++;
                    cnt_to_check = 0;
                } else {
                    cnt_to_check = max(0, cnt_to_check - 1);
                }
            }
            added.pop();
            cur_num++;
            continue;
        }
        cin >> num;
        added.push(num);
        cnt_to_check++;
    }
    cout << cnt << '\n';
}
