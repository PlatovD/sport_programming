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
        vector<ll> kindness(n);
        for (auto &el: kindness) cin >> el;

        vector<ll> prefix(n + 1);
        vector<ll> prefix_inverse(n + 1);

        prefix[0] = 0;
        prefix[1] = kindness[0];
        prefix_inverse[1] = -kindness[0];
        prefix_inverse[0] = 0;
        for (int i = 1; i < n; i++) {
            prefix[i + 1] = prefix[i] + abs(kindness[i]);
            prefix_inverse[i + 1] = prefix_inverse[i] - kindness[i];
        }

        ll best_sum = INT64_MIN;
        for (int i = 0; i < n; i++) {
            best_sum = max(best_sum, prefix[i] + (prefix_inverse[n] - prefix_inverse[i + 1]));
        }

        cout << best_sum << '\n';
    }
}
