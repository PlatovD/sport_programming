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

    int q;
    cin >> q;
    map<string, string> m;
    string s1, s2;
    for (int i = 0; i < q; i++) {
        cin >> s1 >> s2;
        if (m.find(s1) == m.end()) {
            m[s2] = s1;
        } else {
            string last = m[s1];
            m.erase(s1);
            m[s2] = last;
        }
    }
    cout << m.size() << endl;
    for (const auto &[key, value]: m) {
        std::cout << value << " " << key << std::endl;
    }
}
