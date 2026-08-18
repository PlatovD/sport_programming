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
#include <unordered_set>
#define ll long long
#define ld long double
// #define _DEBUG
using namespace std;
ll MOD = 1e9 + 7;

bool compare(vector<int> &a, vector<int> &b, set<int> &elements_used) {
    int ptr_a = 0, ptr_b = 0;
    while (ptr_a < a.size() && ptr_b < b.size()) {
        while (ptr_a < a.size() && elements_used.count(a[ptr_a]))ptr_a++;
        while (ptr_b < b.size() && elements_used.count(b[ptr_b]))ptr_b++;
        if (ptr_a >= a.size() || ptr_b >= b.size()) break;
        if (a[ptr_a] < b[ptr_b]) return true;
        if (a[ptr_a] > b[ptr_b]) return false;
        ptr_a++;
        ptr_b++;
    }
    if (ptr_a == a.size() && ptr_b <= b.size()) return true;
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > a;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        int prev = -1;
        int num;
        vector<int> nums;
        for (int j = m - 1; j >= 0; j--) {
            cin >> num;
            if (num == prev) continue;
            prev = num;
            nums.push_back(num);
        }
        reverse(nums.begin(), nums.end());
        a.push_back(nums);
    }

    vector used(n, false);
    set<int> used_elements;
    vector<int> q;
    vector<int> *best;
    for (int i = 0; i < n; i++) {
        best = new vector(1, INT32_MAX);
        int best_index = -1;
        for (int j = 0; j < n; j++) {
            if (used[j]) continue;
            if (!compare(*best, a[j], used_elements)) {
                best = &a[j];
                best_index = j;
            }
        }
        for (int j: *best) {
            if (used_elements.count(j))continue;
            q.push_back(j);
            used_elements.insert(j);
        }
        used[best_index] = true;
    }

    for (auto el: q) {
        cout << el << " ";
    }
    cout << '\n';
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
