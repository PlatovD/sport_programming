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

        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        sort(b.begin(), b.end(), greater<int>());

        bool is_bad = false;
        for (int i = 2; i < n; i++) {
            if (b[i] != b[i - 2] % b[i - 1]) {
                is_bad = true;
                break;
            }
        }
        if (is_bad) {
            cout << -1 << '\n';
        } else {
            cout << b[0] << ' ' << b[1] << '\n';
        }
    }
}
