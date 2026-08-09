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
    // жадно, но обязательно начинаю с больших по размеру
    string s;
    cin >> s;

    map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
        mp[s[i]]++;

    vector<string> samples = {
        "[:|||:]", "%0", "8-0", ":~(", ":-\\", ":-X", ":-E", ":-P", ":-0", ":-|", ";-)", ";-(", ":)", ":(", ":D", ":C"
    };

    vector<string> ans;
    for (string st: samples) {
        map<char, int> cur_mp;
        for (int i = 0; i < st.length(); i++)
            cur_mp[st[i]]++;
        while (true) {
            bool good = true;
            for (auto kv: cur_mp) {
                if (mp[kv.first] >= cur_mp[kv.first]) continue;
                good = false;
            }
            if (!good) {
                break;
            }
            for (auto kv: cur_mp) {
                mp[kv.first] -= kv.second;
            }
            ans.push_back(st);
        }
    }

    for (const auto &st: ans) cout << st << "\n";
    cout << "LOL";
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
