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

int get_index(string s) {
    if (s == "Rock") return 0;
    if (s == "Scissors") return 1;
    if (s == "Paper") return 2;
    if (s == "Lizard") return 3;
    if (s == "Spock") return 4;
    return -1;
}


void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    std::vector<std::vector<int> > g = {
        {0, 1, 0, 1, 0},
        {0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 0, 0, 0}
    };

    int index_1 = get_index(s1);
    int index_2 = get_index(s2);
    if (g[index_1][index_2]) {
        cout << "First";
    } else if (g[index_2][index_1]) {
        cout << "Second";
    } else {
        cout << "Tie";
    }
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
