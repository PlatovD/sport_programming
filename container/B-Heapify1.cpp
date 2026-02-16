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
#include <functional>
#include <memory>

#define ll long long
using namespace std;

bool can_stand_on_good_pos(int numer, int current_pos, int max_pos) {
    while (current_pos % 2 == 0) {
        current_pos /= 2;
    }
    while (current_pos <= max_pos) {
        if (current_pos == numer) return true;
        current_pos *= 2;
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> perm(n);
        for (auto &el: perm) cin >> el;

        bool bad = false;
        int current_pos = 1;
        for (int i = 0; i < n; i++) {
            if (!can_stand_on_good_pos(perm[i], current_pos, n)) {
                bad = true;
                break;
            }
            current_pos++;
        }

        if (bad) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
}
