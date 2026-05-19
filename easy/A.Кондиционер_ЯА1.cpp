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
#define str string
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

    int t0, t1;
    cin >> t0 >> t1;
    str s;
    cin >> s;

    if (s == "auto") {
        cout << t1 << endl;
    }
    if (s == "fan") {
        cout << t0 << endl;
    }
    if (s == "heat") {
        cout << max(t0, t1) << endl;
    }
    if (s == "freeze") {
        cout << min(t0, t1) << endl;
    }
}
