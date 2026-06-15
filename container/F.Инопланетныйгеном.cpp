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
#include <algorithm>
#include <random>
#include <iomanip>
#include <assert.h>

#define ll long long
using namespace std;

int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;

    map<string, int> first;
    for (int i = 1; i < a.length(); i++) {
        string temp = a.substr(i - 1, 2);
        first[temp]++;
    }

    int total = 0;
    for (int i = 1; i < b.length(); i++) {
        string temp = b.substr(i - 1, 2);
        if (first.find(temp) != first.end()) {
            total += first[temp];
        }
    }

    cout << total << endl;
}
