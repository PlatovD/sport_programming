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

struct Comporator {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    }
};

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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        priority_queue<pair<int, int>, vector<pair<int, int> >, Comporator> pq;
        vector<pair<int, int> > v;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;

            pq.push({num, i + 1});
        }

        int res = 0;
        while (pq.size() > 1) {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();

            if (a.first > 0 && b.first > 0) {
                v.emplace_back(a.second, b.second);
                res += 1;

                a.first -= 1;
                b.first -= 1;
            }

            if (a.first > 0) pq.push(a);
            if (b.first > 0) pq.push(b);
        }

        cout << res << endl;
        for (auto &i: v) {
            cout << i.first << " " << i.second << endl;
        }
    }
}
