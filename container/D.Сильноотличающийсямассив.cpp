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
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<ll> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int l_m = 0;
        int r_m = m - 1;
        int l_n = 0;
        int r_n = n - 1;
        ll sum_res = 0;
        while (l_n <= r_n) {
            ll res1_for_l = abs(a[l_n] - b[l_m]);
            ll res2_for_l = abs(a[l_n] - b[r_m]);

            ll res1_for_r = abs(a[r_n] - b[l_m]);
            ll res2_for_r = abs(a[r_n] - b[r_m]);

            if (max(res1_for_l, res2_for_l) > max(res1_for_r, res2_for_r)) {
                if (res1_for_l > res2_for_l) {
                    sum_res += res1_for_l;
                    l_n++;
                    l_m++;
                } else {
                    sum_res += res2_for_l;
                    l_n++;
                    r_m--;
                }
            } else {
                if (res1_for_r > res2_for_r) {
                    sum_res += res1_for_r;
                    r_n--;
                    l_m++;
                } else {
                    sum_res += res2_for_l;
                    r_n--;
                    r_m--;
                }
            }
        }
        cout << sum_res << '\n';
    }
}
