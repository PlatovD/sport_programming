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
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<ll> prefix_xor(n + 1);
        prefix_xor[0] = 0;
        for (int i = 0; i < n; i++) {
            prefix_xor[i + 1] = prefix_xor[i] ^ a[i];
        }

        bool good = false;
        for (int i = 1; i < n; i++) {
            if (prefix_xor[i] == (prefix_xor[n] ^ prefix_xor[i])) {
                good = true;
                break;
            }
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prefix_xor[i] == (prefix_xor[j] ^ prefix_xor[i]) && prefix_xor[i] == (
                        prefix_xor[n] ^ prefix_xor[j])) {
                    good = true;
                    break;
                }
            }
        }

        cout << (good ? "YES" : "NO") << endl;
    }
}
