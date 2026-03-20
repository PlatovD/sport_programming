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
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        ll sum = 0;
        int l = -1;
        int r = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                if (l < 0) {
                    l = i;
                    r = i;
                } else {
                    r = i;
                }
            }
            sum += abs(a[i]);
        }

        if (l == -1) {
            cout << sum << '\n';
            cout << 0 << '\n';
            continue;
        }
        // нужен первый и последний отрицательные
        map<char, int> sub_seq_cnt;
        sub_seq_cnt['+'] = 0;
        sub_seq_cnt['-'] = 1;
        int last_num = a[l];
        for (int i = l; i < r + 1; i++) {
            if (last_num < 0 && a[i] > 0) {
                sub_seq_cnt['+'] += 1;
            } else if (last_num > 0 && a[i] < 0) {
                sub_seq_cnt['-'] += 1;
            }
            if (a[i] != 0) {
                last_num = a[i];
            }
        }
        cout << sum << ' ';
        cout << min(sub_seq_cnt['+'] + 1, sub_seq_cnt['-']) << '\n';
    }
}
