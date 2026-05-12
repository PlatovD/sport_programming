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

    int n;
    cin >> n;
    stack<string> st;
    set<string> written;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.push(s);
    }
    while (!st.empty()) {
        string cur = st.top();
        if (written.find(cur) != written.end()) {
            st.pop();
            continue;
        }
        cout << cur << endl;
        written.insert(cur);
        st.pop();
    }
}
