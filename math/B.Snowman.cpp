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


int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    double s, h;
    cin >> s >> h;
    double l, r;
    cin >> l >> r;

    double total_snow = s * h / 100;
    double a = (r + l) / 2;
    double b = (r + l) / 2;
    double x = total_snow / (1 + a + a * b);
    cout << x << ' ';
    cout << x * a << ' ';
    cout << x * a * b;
}
