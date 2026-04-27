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

bool was_border(int n) {
    
}

int find_right_border(int n) {
    int right_border = -1;
    int l = 0;
    int r = n;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (was_border(mid)) {
            right_border = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return right_border;
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
        cout << flush;

        find_right_border(n);
    }
}
