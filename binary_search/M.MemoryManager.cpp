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
    int n, k;
    cin >> n >> k;
    set<int> avail;
    set<int> avail_neg;
    for (int i = 0; i < n; i++) {
        avail.insert(i);
        avail_neg.insert(-i);
    }
    int request;
    for (int i = 0; i < k; i++) {
        cin >> request;
        auto it = avail.lower_bound(request);
        int left = INT32_MAX;
        int right = INT32_MAX;
        if (it != avail.end()) {
            left = *it;
            if (left == request) {
                cout << left << '\n';
                avail.erase(left);
                avail_neg.erase(-left);
                continue;
            }
        }
        it = avail_neg.upper_bound(-request);
        if (it != avail_neg.end()) {
            right = abs(*it);
        }
        int res = abs(right - request) <= abs(left - request) ? right : left;
        avail.erase(res);
        avail_neg.erase(-res);
        cout << res << '\n';
    }
}
