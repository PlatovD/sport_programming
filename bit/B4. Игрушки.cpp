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
using namespace std;

void print(vector<string> &rgs) {
    vector<string> ans;
    for (string s: rgs) {
        map<int, vector<int> > heaps;
        for (int i = 0; i < s.size(); i++) {
            heaps[s[i] - '0'].push_back(i + 1);
        }

        for (auto &kv: heaps) {
            sort(kv.second.begin(), kv.second.end());
        }

        string res;
        res.reserve(10);
        bool first = true;
        for (auto &kv: heaps) {
            if (!first) {
                res += ',';
            } else {
                first = false;
            }
            res += '{';

            for (int i = 0; i < kv.second.size(); i++) {
                if (i != 0) res += ',';
                res += to_string(kv.second[i]);
            }
            res += '}';
        }
        ans.push_back(res);
    }

    cout << ans.size() << '\n';
    for (auto &s: ans) {
        cout << s << '\n';
    }
}

vector<string> next_rgs(vector<string> &current_rgs) {
    vector<string> next_rgs;

    for (int i = 1; i <= current_rgs.size(); i++) {
        const string &old_rgs = current_rgs[i - 1];
        int m = 0;
        for (int j = 0; j < old_rgs.size(); j++) {
            m = std::max(old_rgs[j] - '0', m);
        }
        m++;

        if (i % 2 == 1) {
            next_rgs.push_back(old_rgs + "0");
            for (int j = m; j > 0; j--) {
                next_rgs.push_back(old_rgs + to_string(j));
            }
        } else {
            for (int j = 1; j <= m; j++) {
                next_rgs.push_back(old_rgs + to_string(j));
            }
            next_rgs.push_back(old_rgs + "0");
        }
    }

    return next_rgs;
}

void solve() {
    int n;
    cin >> n;

    vector<string> res = {"0"};
    for (int i = 0; i < n - 1; i++) {
        res = next_rgs(res);
    }
    print(res);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
