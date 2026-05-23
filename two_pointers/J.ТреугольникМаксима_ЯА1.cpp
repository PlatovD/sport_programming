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

    int n;
    cin >> n;
    double f;
    string s;

    double l = 30, r = 4000;
    double last;
    cin >> last;
    n--;
    while (n--) {
        cin >> f;
        cin >> s;
        if (last == f) continue;
        if (s == "closer") {
            if (f > last) {
                l = max(last + (f - last) / 2, l);
            } else {
                r = min(f + (last - f) / 2, r);
            }
        } else {
            if (f > last) {
                r = min(last + (f - last) / 2, r);
            } else {
                l = max(f + (last - f) / 2, l);
            }
        }

        last = f;
    }

    cout << l << ' ' << r << '\n';
}
