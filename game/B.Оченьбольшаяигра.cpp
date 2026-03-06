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
    vector<int> a(n);
    map<int, pair<int, int> > repeats;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        repeats[a[i]] = {0, 0};
    }


    int last_el = -1;
    int strike = 0;
    for (auto el: a) {
        if (last_el == el) {
            strike++;
        } else {
            // обновляем
            pair<int, int> for_el = repeats[last_el];
            if (strike > for_el.first) {
                for_el.second = for_el.first;
                for_el.first = strike;
            } else if (strike > for_el.second) {
                for_el.second = strike;
            }
            repeats[last_el] = for_el;
            strike = 1;
            last_el = el;
        }
    }

    pair<int, int> for_el = repeats[last_el];
    if (strike > for_el.first) {
        for_el.second = for_el.first;
        for_el.first = strike;
    } else if (strike > for_el.second) {
        for_el.second = strike;
    }
    repeats[last_el] = for_el;

    int max_repeats = 1;
    for (const auto &[key, value]: repeats) {
        max_repeats = max(max_repeats, value.first + value.second);
    }
    cout << max_repeats << '\n';
}
