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

    vector<int> prefix(3 * 1e5 + 1);
    prefix[0] = 0;
    for (int i = 1; i < 3 * 1e5 + 1; i++) {
        prefix[i] = prefix[i - 1] ^ i;
    }

    while (t--) {
        int a, b;
        cin >> a >> b;

        int xor_for_a = prefix[a - 1];
        if (xor_for_a == b) {
            cout << a << '\n';
        } else if ((xor_for_a ^ a) == b) {
            cout << a + 2 << '\n';
        } else {
            cout << a + 1 << '\n';
        }
    }
}
