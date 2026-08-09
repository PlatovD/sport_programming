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


void solve() {
    string s;
    getline(cin, s);

    int n;
    cin >> n;
    unordered_map<string, string> st;
    while (n--) {
        string start, sorted;
        cin >> start;
        sorted = start;
        if (start.size() > 3)
            sort(next(sorted.begin()), prev(sorted.end()));
        st[sorted] = start;
    }

    vector<string> ans;
    bool bad = false;
    for (int i = 0; i < s.size(); i++) {
        int start = i;
        while (s[i] != ' ' && s[i] != '.') {
            i++;
        }
        string cur = s.substr(start, i - start);
        if (cur.size() > 3)
            sort(next(cur.begin()), prev(cur.end()));
        if (!st.count(cur)) {
            bad = true;
            break;
        }
        ans.push_back(st[cur]);
    }

    if (bad) {
        cout << "No solution";
        return;
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '.';
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
    // cin >> t;
    while (t--) {
        solve();
    }
}
