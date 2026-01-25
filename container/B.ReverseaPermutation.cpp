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
// #define _DEBUG

#define ll long long
using namespace std;

void rotate(vector<int> &v, int from, int to) {
    int l = from;
    int r = to;
    int tmp;
    while (l < r) {
        tmp = v[l];
        v[l] = v[r];
        v[r] = tmp;
        l++;
        r--;
    }
}

int main() {
#if defined _DEBUG
    freopen("rvq.in", "r", stdin);
    freopen("rvq.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (auto &el: p) cin >> el;

        int lasted_max = n; // оставшийся максимальный
        int start_rotating = 0;
        bool was_skip = false;
        for (int i = 0; i < n; i++) {
            if (p[i] == lasted_max && !was_skip) {
                lasted_max--;
                start_rotating++;
                continue;
            }
            if (p[i] == lasted_max && was_skip) {
                rotate(p, start_rotating, i);
                break;
            }
            was_skip = true;
        }
        for (auto el: p) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}
