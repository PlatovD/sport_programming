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
#define ld long double
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;


void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> w;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        w[num]++;
    }

    int best = 0;
    for (int i = 2; i < 2 * n + 1; i++) {
        int current = 0;
        for (int j = 1; j <= i / 2; j++) {
            int left = j;
            int right = i - j;
            if (left == right)
                current += w[left] / 2;
            else current += min(w[left], w[right]);
        }
        best = max(best, current);
    }
    cout << best << '\n';
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
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
