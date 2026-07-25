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
#include <cstdint>
#include <set>
#include <algorithm>
#include <random>
#include <iomanip>
#include <assert.h>

#define ll long long
#define ld long double
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;


void solve() {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            q.push(i);
            n /= i;
        }
    }
    if (n > 1) q.push(n);

    set<int> decomposition_has;
    vector<int> decomposition;
    int current_mul = 1;
    while (!q.empty()) {
        current_mul *= q.front();
        if (decomposition.size() == 3) {
            decomposition[3 - 1] *= current_mul;
            current_mul = 1;
        } else if (decomposition.empty()) {
            decomposition.push_back(current_mul);
            decomposition_has.insert(current_mul);
            current_mul = 1;
        } else {
            if (decomposition_has.find(current_mul) == decomposition_has.end()) {
                decomposition.push_back(current_mul);
                decomposition_has.insert(current_mul);
                current_mul = 1;
            }
        }

        q.pop();
    }

    if (decomposition.size() < 3) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (auto num: decomposition) {
            cout << num << " ";
        }
        cout << '\n';
    }
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
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}
