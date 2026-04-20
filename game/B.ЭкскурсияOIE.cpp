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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool flag = false;
        ll last = a[0];
        ll cnt = 1;
        for (int i = 1; i < n; i++) {
            if (last == a[i]) {
                cnt++;
            } else {
                last = a[i];
                cnt = 1;
            }
            if (cnt == m) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
    }
}
