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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<set<char> > symbols_by_cols(m);
        for (int i = 0; i < m; i++) {
            symbols_by_cols[i] = set<char>();
        }

        for (int i = 0; i < n; i++) {
            string inp;
            cin >> inp;
            for (int j = 0; j < m; j++) {
                symbols_by_cols[j].insert(inp[j]);
            }
        }

        string s = "vika";
        int symbol_for_find_index = 0;
        for (int i = 0; i < m && symbol_for_find_index != 4; i++) {
            if (symbols_by_cols[i].find(s[symbol_for_find_index]) != symbols_by_cols[i].end())
                symbol_for_find_index++;
        }
        if (symbol_for_find_index == 4) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}
