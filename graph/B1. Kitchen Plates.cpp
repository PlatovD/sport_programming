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

vector<vector<int> > g(5);

vector<int> top_sort;

vector viewed(5, 0);

bool dfs(int v) {
    viewed[v] = 1;
    for (auto con: g[v]) {
        if (viewed[con] == 0) {
            viewed[con] = 1;
            if (dfs(con)) return true;
        }
        if (viewed[con] == 1) return true;
    }
    top_sort.push_back(v);
    viewed[v] = 2;
    return false;
}

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


    string s;
    for (int i = 0; i < 5; i++) {
        cin >> s;
        int u = s[0] - 'A';
        int k = s[2] - 'A';
        if (s[1] == '>') {
            g[k].push_back(u);
        } else {
            g[u].push_back(k);
        }
    }

    for (int i = 0; i < 5; i++) {
        if (viewed[i] == 2) continue;

        if (dfs(i)) {
            cout << "impossible";
            return 0;
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    for (auto v: top_sort) {
        cout << (char) ('A' + v);
    }
}
