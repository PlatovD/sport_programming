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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        for (int i = 0; i < n - k; i++) {
            if (s[i] == '1') {
                s[i] = '0';
                if (s[i + k] == '0') {
                    s[i + k] = '1';
                } else {
                    s[i + k] = '0';
                }
            }
        }
        bool is_good = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                is_good = false;
                break;
            }
        }
        if (is_good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
