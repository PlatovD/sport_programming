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

    int x;
    vector<int> v;
    while (true) {
        cin >> x;
        if (x == -2000000000) break;
        v.push_back(x);
    }

    bool CONSTANT = true;
    bool ASCENDING = true;
    bool WEAKLY_ASCENDING = true;
    bool DESCENDING = true;
    bool WEAKLY_DESCENDING = true;

    int n = v.size();
    for (int i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) CONSTANT = false;
        if (v[i] <= v[i - 1]) ASCENDING = false;
        if (v[i] < v[i - 1]) WEAKLY_ASCENDING = false;
        if (v[i] >= v[i - 1]) DESCENDING = false;
        if (v[i] > v[i - 1]) WEAKLY_DESCENDING = false;
    }

    if (CONSTANT) {
        cout << "CONSTANT";
        return 0;
    }
    if (ASCENDING) {
        cout << "ASCENDING";
        return 0;
    }
    if (WEAKLY_ASCENDING) {
        cout << "WEAKLY ASCENDING";
        return 0;
    }
    if (DESCENDING) {
        cout << "DESCENDING";
        return 0;
    }
    if (WEAKLY_DESCENDING) {
        cout << "WEAKLY DESCENDING";
        return 0;
    }
    cout << "RANDOM";
    return 0;
}
