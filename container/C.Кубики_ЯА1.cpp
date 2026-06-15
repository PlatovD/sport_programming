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

    int n, m;
    cin >> n >> m;

    set<int> a;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.insert(num);
    }

    set<int> b;
    for (int i = 0; i < m; i++) {
        cin >> num;
        b.insert(num);
    }

    set a_copy(a.begin(), a.end());
    set<int> c;
    for (auto el: a_copy) {
        if (b.find(el) != b.end()) {
            c.insert(el);
            b.erase(el);
            a.erase(el);
        }
    }
    cout << c.size() << endl;
    for (auto el: c) {
        cout << el << " ";
    }
    cout << endl;
    cout << a.size() << endl;
    for (auto el: a) {
        cout << el << " ";
    }
    cout << endl;
    cout << b.size() << endl;
    for (auto el: b) {
        cout << el << " ";
    }
    cout << endl;
}
