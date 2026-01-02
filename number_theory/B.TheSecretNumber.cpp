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
        ll n;
        cin >> n;
        vector<ll> current;
        for (int i = 1; i < 18; i++) {
            ll ten = pow(10, i);
            ll x = n / (1 + ten);
            if (x + x * ten == n) current.push_back(x);
        }
        sort(current.begin(), current.end());
        cout << current.size() << '\n';
        if (current.size() == 0) continue;
        for (auto el: current) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}
