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

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    pair best_indices = {0, 0};
    int l = 0, r = 0;
    unordered_map<int, int> inside_current;
    inside_current[a[0]] = 1;
    while (true) {
        if (best_indices.second - best_indices.first + 1 < r - l + 1) {
            best_indices = {l, r};
        }
        r++;
        if (r == n) break;
        inside_current[a[r]] += 1;
        while (inside_current.size() > k) {
            inside_current[a[l]] -= 1;
            if (inside_current[a[l]] <= 0) {
                inside_current.erase(a[l]);
            }
            l++;
        }
    }
    cout << best_indices.first + 1 << ' ' << best_indices.second + 1 << endl;
}
