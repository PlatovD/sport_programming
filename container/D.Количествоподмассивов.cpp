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

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    int total = 0;
    int sum = a[0];
    unordered_map<int, int> was_prefix;
    for (int i = 1; i < n + 1; i++) {
        int req = sum - x;
        if (req == 0) total++;
        if (was_prefix.count(req)) {
            total += was_prefix[req];
        }
        was_prefix[sum]++;
        if (i != n) {
            sum += a[i];
        }
    }
    cout << total << endl;
}
