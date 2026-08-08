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

struct node {
    char ch;
    int pos;
    int len;
};

struct comparator {
    bool operator()(node &a, node &b) {
        if (a.len != b.len)
            return a.len < b.len;
        return a.pos > b.pos;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    priority_queue<node, vector<node>, comparator> pq;

    char cur = s[0];
    int len = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == cur) {
            len++;
            continue;
        }

        pq.push({cur, i - len, len});
        cur = s[i];
        len = 1;
    }
    pq.push({cur, n - len, len});

    while (k--) {
        node head = pq.top();
        pq.pop();

        head.len--;
        if (head.len != 0)
            pq.push(head);
    }

    vector<node> res;
    while (!pq.empty()) {
        node current = pq.top();
        res.push_back(current);
        pq.pop();
    }

    sort(res.begin(), res.end(), [](node &a, node &b) { return a.pos < b.pos; });
    string ans;
    ans.reserve(10);
    for (auto node: res) {
        for (int i = 0; i < node.len; i++) {
            ans += node.ch;
        }
    }
    cout << ans;
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
