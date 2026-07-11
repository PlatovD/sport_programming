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

    int n;
    cin >> n;

    vector<int> f(n);
    for (int i = 0; i < n; i++) cin >> f[i];

    for (int i = 0; i < n; i++) {
        int current_likes = f[i] - 1;
        int current_likes_likes = f[current_likes] - 1;
        if (i == f[current_likes_likes] - 1) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
