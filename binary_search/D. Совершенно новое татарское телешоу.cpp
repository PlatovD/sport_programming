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

pair<int, int> find_borders(vector<int> &a, int mi, int ma, int n) {
    int l = 0, r = n - 1;
    int left_border = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < mi) {
            l = mid + 1;
        } else {
            left_border = mid;
            r = mid - 1;
        }
    }

    l = 0, r = n - 1;
    int right_border = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] <= ma) {
            right_border = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return {left_border, right_border};
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        vector<pair<int, int> > A = {{a[0], 1}};
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) A.back().second++;
            else A.emplace_back(a[i], 1);
        }

        bool is_good = false;
        while (!A.empty()) {
            n = A.size();
            if (A[n - 1].second % 2 == 0) {
                is_good = true;
                break;
            }
            if (n == 1) {
                break;
            }
            if (abs(A[n - 2].first - A[n - 1].first) <= k) {
                is_good = true;
                break;
            }
            A.pop_back();
        }
        if (is_good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
