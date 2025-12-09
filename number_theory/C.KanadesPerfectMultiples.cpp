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

set<int> a;
set<int> viewed;
set<int> bad_dividers;
set<int> dividers;

bool is_ok(int divider, int k) {
    for (int i = divider; i <= k; i += divider) {
        if (a.find(i) == a.end()) return false;
    }
    for (int i = divider; i <= k; i += divider) {
        viewed.insert(i);
    }
    return true;
}

int find_divider(int num, int k) {
    for (int i = 1; i * i <= num; i++) {
        if (bad_dividers.find(i) == bad_dividers.end()) {
            if (num % i != 0) continue;
            if (is_ok(i, k)) {
                return i;
            }
        }
        bad_dividers.insert(i);
        if (bad_dividers.find(num / i) != bad_dividers.end()) continue;
        if (is_ok(num / i, k)) {
            return num / i;
        }
        bad_dividers.insert(num / i);
    }
    return -1;
}

void clear_globals() {
    a.clear();
    viewed.clear();
    bad_dividers.clear();
    dividers.clear();
}


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
    for (int q = 0; q < t; q++) {
        int n, k;
        cin >> n >> k;


        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            a.insert(num);
        }
        bool is_bad = false;
        for (int val: a) {
            if (viewed.find(val) != viewed.end()) continue;
            int divider = find_divider(val, k);
            if (divider < 0) {
                is_bad = true;
                break;
            }
            dividers.insert(divider);
        }
        if (is_bad) {
            cout << -1 << '\n';
            clear_globals();
            continue;
        }
        cout << dividers.size() << '\n';
        for (const int div: dividers)
            cout << div << ' ';
        cout << '\n';
        clear_globals();
    }
}
