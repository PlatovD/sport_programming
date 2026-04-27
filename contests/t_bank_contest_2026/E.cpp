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

bool in_normal(char ch) {
    return ch == 'O' || ch == 'I' || ch == 'T';
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

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> min_actions(n);
    for (int i = 0; i < n; i++) {
        int current_actions = 0;
        int l = i;
        int r = i + 1;
        if (n % 2 == 1) {
            if (!in_normal(s[i]))
                current_actions++;
            l--;
        }
        while (l >= 0 && r < n) {
            if (s[l] == s[r]) {
                if (!in_normal(s[l])) current_actions += 2;
            } else {
                if (!in_normal(s[l]) && !in_normal(s[r])) {
                    current_actions += 2;
                } else current_actions++;
            }
            l--;
            r++;
        }
        int r_before_end = n - r;
        int l_before_end = l;
        int diff = max(l_before_end, r_before_end);
        min_actions[i] = current_actions + diff;
    }
    sort(min_actions.begin(), min_actions.end());
    cout << min_actions[0] << endl;
}
