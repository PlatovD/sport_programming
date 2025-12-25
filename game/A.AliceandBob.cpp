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
        int n, a;
        cin >> n >> a;
        int bigger = 0;
        int lower = 0;
        int current = 0;
        while (n--) {
            cin >> current;
            if (current > a) {
                bigger++;
            } else if (current < a) {
                lower++;
            }
        }
        if (bigger >= lower) {
            cout << a + 1 << '\n';
        } else {
            cout << a - 1 << '\n';
        }
    }
}
