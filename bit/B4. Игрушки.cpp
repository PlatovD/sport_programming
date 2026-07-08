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
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;

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
    vector v(n * n, 0);
    for (int i = n * (n - 1); i < n * n; i++) {
        v[i] = 1;
    }

    set<string> already_added;
    vector<string> ans;
c:
    do {
        string total;
        total.reserve(10);
        bool is_first = true;
        for (int i = 0; i < n; i++) {
            string cur;
            cur.reserve(10);
            bool first = true;
            for (int j = i * n; j < (i + 1) * n; j++) {
                if (v[j]) {
                    if (first) {
                        cur += to_string(j % n + 1);
                        first = false;
                    } else {
                        cur += "," + to_string(j % n + 1);
                    }
                }
            }
            if (!cur.empty()) {
                cur = "{" + cur + "}";
                if (!is_first)
                    total += "," + cur;
                else {
                    is_first = false;
                    total += cur;
                }
            }
        }
        if (already_added.find(total) != already_added.end()) continue;
        already_added.insert(total);
        ans.push_back(total);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans.size() << endl;
    for (const auto &num: ans) cout << num << "\n";
}
