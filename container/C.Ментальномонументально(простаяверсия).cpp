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


bool can_reach(multiset<int> &ms, int k, vector<int> &removed) {
    if (k > ms.size()) return false;
    for (int i = k - 1; i > -1; i--) {
        if (ms.count(i)) {
            ms.erase(ms.find(i));
            removed.push_back(i);
        } else {
            int last = *ms.rbegin();
            if (last < i * 2 + 1) {
                return false;
            }
            ms.erase(ms.find(last));
            removed.push_back(last);
        }
    }
    return true;
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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        multiset ms(a.begin(), a.end());

        int l = 0;
        int r = n + 1;
        int last_good = 0;
        while (l <= r) {
            vector<int> removed;
            int mid = (l + r) / 2;
            if (can_reach(ms, mid, removed)) {
                last_good = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            for (auto num: removed) {
                ms.insert(num);
            }
        }
        cout << last_good << endl;
    }
}
