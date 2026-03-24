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
        string s, f;
        cin >> s >> f;

        int res_days = 0;

        // сначала сравнять число требуемых и наличных котов
        int cnt_cats_have = 0;
        int cnt_cats_req = 0;
        int cnt_cats_not_on_pos = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt_cats_have++;
            }
            if (f[i] == '1') {
                cnt_cats_req++;
            }
            if (f[i] == '1' && f[i] != s[i]) {
                cnt_cats_not_on_pos++;
            }
        }

        res_days += abs(cnt_cats_have - cnt_cats_req);
        if (cnt_cats_have < cnt_cats_req) {
            cnt_cats_not_on_pos -= cnt_cats_req - cnt_cats_have;
        }
        res_days += cnt_cats_not_on_pos;
        cout << res_days << '\n';
    }
}
