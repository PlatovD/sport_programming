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
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        vector<int> even;
        vector<int> odd;
        for (int i = 0; i < n; i++) {
            if (v[i] % 2 == 0) {
                even.push_back(v[i]);
            } else {
                odd.push_back(v[i]);
            }
        }

        int even_min = 1e9;
        int even_max = -1e9;
        int odd_min = 1e9;
        int odd_max = -1e9;


        for (auto x: even) {
            even_min = min(even_min, x);
            even_max = max(even_max, x);
        }


        for (auto x: odd) {
            odd_min = min(odd_min, x);
            odd_max = max(odd_max, x);
        }

        bool is_bad = false;

        if (even.size() > 1) {
            int mx = even[0];
            for (int i = 1; i < even.size(); i++) {
                if (even[i] < mx) {
                    if (odd_min > even[i] && odd_max < mx) {
                        is_bad = true;
                        break;
                    }
                } else {
                    mx = even[i];
                }
            }
        }

        if (odd.size() > 1) {
            int mx = odd[0];
            for (int i = 1; i < odd.size(); i++) {
                if (odd[i] < mx) {
                    if (even_min > odd[i] && even_max < mx) {
                        is_bad = true;
                        break;
                    }
                } else {
                    mx = odd[i];
                }
            }
        }

        if (is_bad) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
