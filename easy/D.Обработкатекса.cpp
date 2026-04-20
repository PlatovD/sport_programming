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

int get_sym(char ch) {
    if (ch == '.')
        return 26;
    if (ch == ',')
        return 27;
    if (ch == '?')
        return 28;
    if (ch == '!')
        return 29;
    if (ch == ' ')
        return 30;
    return ch - 'a';
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
    vector<vector<string> > v = {
        {
            ".*", ".*", "..", "..", ".*", "..", "..", ".*", "*.", "*.", ".*", ".*", "..", "..", ".*", "..", "..", ".*",
            "*.", "*.", ".*", ".*", "*.", "..", "..", ".*", "**", "**", "**", "**", "**"
        },
        {
            "**", ".*", "**", "*.", "*.", ".*", "..", "..", ".*", "..", "**", ".*", "**", "*.", "*.", ".*", "..", "..",
            ".*",
            "..", "**", ".*", "..", "**", "*.", "*.", "..", ".*", ".*", "..", "**"
        },
        {
            "**", "**", "**", "**", "**", "**", "**", "**", "**", "**", ".*", ".*", ".*", ".*", ".*", ".*", ".*", ".*",
            ".*",
            ".*", "..", "..", "*.", "..", "..", "..", "*.", "**", "*.", ".*", "**"
        },
    };
    string s;
    getline(cin, s);

    string res0;
    res0.reserve(s.length() * 2);
    string res1;
    res1.reserve(s.length() * 2);
    string res2;
    res2.reserve(s.length() * 2);
    for (auto ch: s) {
        res0 += v[0][get_sym(ch)];
        res1 += v[1][get_sym(ch)];
        res2 += v[2][get_sym(ch)];
    }
    cout << res0 << '\n';
    cout << res1 << '\n';
    cout << res2 << '\n';
}
