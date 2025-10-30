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
    vector<int> arr(n);
    vector from(n, -1);
    // буду хранить {число, {длина, индекс}}
    map<int, pair<int, int> > was;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[i] = num;
        if (was.find(num) != was.end()) continue;
        was[num] = {1, i};
    }
    int max_num = -1;
    int best_l = -1;
    for (int i = 0; i < n; i++) {
        if (was.find(arr[i] - 1) == was.end()) continue;
        if (was[arr[i] - 1].second < i) {
            if (was[arr[i]].first < was[arr[i] - 1].first + 1) {
                was[arr[i]].first = was[arr[i] - 1].first + 1;
                from[i] = was[arr[i] - 1].second;
            }
            if (was[arr[i]].first > best_l) {
                best_l = was[arr[i]].first;
                max_num = i;
            }
        }
    }
    if (max_num == -1) {
        cout << 1 << '\n';
        cout << 1 << '\n';
        return 0;
    }

    stack<ll> indexes;
    indexes.push(max_num);
    int val = arr[max_num];
    for (int i = max_num - 1; i > -1; i--) {
        if (arr[i] == val - 1) {
            indexes.push(i);
            val = arr[i];
        }
    }
    cout << indexes.size() << '\n';
    while (!indexes.empty()) {
        cout << indexes.top() + 1 << ' ';
        indexes.pop();
    }
}
