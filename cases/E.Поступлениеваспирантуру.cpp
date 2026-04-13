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
    ll k;
    cin >> n >> k;

    int m;
    cin >> m;
    set<ll> others;
    map<ll,ll> counts;
    ll num;
    for (int i = 0; i < m; i++) {
        cin >> num;
        others.insert(num);
        if (counts.find(num) != counts.end()) {
            counts[num]++;
        } else {
            counts[num] = 1;
        }
    }

    int is_bad = 2;
    auto itr = others.rbegin();
    while (itr != others.rend()) {
        if (*itr > k) {
            n -= counts[*itr];
            if (n <= 0) {
                is_bad = 0;
                break;
            }
        }
        if (*itr == k) {
            if (n - counts[*itr] - 1 >= 0) {
                is_bad = 2;
                break;
            }
            is_bad = 1;
            break;
        }
        if (*itr < k) {
            is_bad = 2;
            break;
        }
        ++itr;
    }

    if (is_bad == 0) {
        cout << "no chance" << '\n';
    } else if (is_bad == 1) {
        cout << "entrance exams" << '\n';
    } else {
        cout << "enter" << '\n';
    }
}
