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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    pair dimensions = {a + c, max(b, d)};
    int min_s = dimensions.first * dimensions.second;

    if ((b + d) * max(a, c) < min_s) {
        dimensions = {max(a, c), b + d};
        min_s = dimensions.first * dimensions.second;
    }

    if ((a + d) * max(b, c) < min_s) {
        dimensions = {a + d, max(b, c)};
        min_s = dimensions.first * dimensions.second;
    }

    if (max(a, d) * (b + c) < min_s) {
        dimensions = {max(a, d), b + c};
    }

    cout << dimensions.first << ' ' << dimensions.second << endl;
}
