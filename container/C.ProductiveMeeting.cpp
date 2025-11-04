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

struct Comparator {
    bool operator()(pair<int, int> a, pair<int, int> b) {
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

    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int n;
        cin >> n;
        priority_queue<pair<int, int>, vector<pair<int, int> >, Comparator> sociable;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            if (num == 0) continue;
            sociable.push({num, i});
        }
        vector<pair<int, pair<int, int> > > answer;
        int cnt = 0;
        while (sociable.size() > 1) {
            pair<int, int> person1 = sociable.top();
            sociable.pop();
            pair<int, int> person2 = sociable.top();
            sociable.pop();
            cnt += 1;
            answer.push_back({1, {person1.second, person2.second}});
            person1.first -= 1;
            person2.first -= 1;
            if (person1.first > 0) sociable.push(person1);
            if (person2.first > 0) sociable.push(person2);
        }

        cout << cnt << '\n';
        for (auto res: answer) {
            for (int j = 0; j < res.first; j++) {
                cout << res.second.first + 1 << ' ' << res.second.second + 1 << '\n';
            }
        }
    }
}
