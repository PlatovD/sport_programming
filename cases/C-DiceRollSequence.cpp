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
#include <functional>
#include <memory>

#define ll long long
using namespace std;
map<int, vector<int> > adj = {
    {1, {2, 3, 4, 5}},
    {2, {1, 3, 4, 6}},
    {3, {1, 2, 5, 6}},
    {4, {1, 2, 5, 6}},
    {5, {1, 3, 4, 6}},
    {6, {2, 3, 4, 5}}
};

int find(int a, int b) {
    for (int first: adj[a]) {
        for (int second: adj[b]) {
            if (first == second) return first;
        }
    }
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> throws(n);
        for (auto &el: throws) cin >> el;

        int cnt = 0;
        for (int i = 1; i < n; i++) {
            int last = throws[i - 1];
            int current = throws[i];
            if (last != current && last + current != 7) continue;
            if (i != n - 1) {
                throws[i] = find(last, throws[i + 1]);
            }
            cnt++;
        }

        cout << cnt << '\n';
    }
}
