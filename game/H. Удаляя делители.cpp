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
#include <cstdint>
#include <set>
#include <algorithm>
#include <random>
#include <iomanip>
#include <assert.h>

#define ll long long
#define ld long double
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;

int mex(set<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums.find(i) == nums.end()) {
            return i;
        }
    }
    return nums.size();
}

int dfs(int num, vector<int> &grandy) {
    if (num == 1) {
        grandy[num] = 0;
        return grandy[num];
    }

    if (grandy[num] != -1) return grandy[num];

    set<int> nums;
    for (ll i = 2; i * i <= num; i++) {
        if (num % i != 0) continue;
        nums.insert(dfs(num - i, grandy));
        nums.insert(dfs(num - num / i, grandy));
    }
    int cur_mex = mex(nums);
    grandy[num] = cur_mex;
    return cur_mex;
}

bool is_power_of_two(ll num) {
    ll power = 1;
    while (power < num) power <<= 1;
    return power == num;
}

int get_power_of_2(ll num) {
    ll power = 1;
    int cnt = 0;
    while (power < num) {
        power <<= 1;
        cnt++;
    }
    return cnt;
}

void solve() {
    ll n;
    cin >> n;
    // n = 1e4;

    // vector grandy(n, -1);
    // for (int i = 1; i < n; i++) {
    //     if (grandy[i] != -1) continue;
    //     dfs(i, grandy);
    // }
    //
    // for (int i = 1; i < n; i++) {
    //     if (grandy[i] != 0)
    //         cout << i << " ";
    // }

    // все четные это Alice при этом, все нечетные это Bob, и к тому же Bob когда n - это степень двойки и нечетная степень двойки
    if (n % 2 == 1) {
        cout << "Bob" << '\n';
    } else {
        if (is_power_of_two(n)) {
            if (get_power_of_2(n) % 2 == 1) {
                cout << "Bob" << '\n';
                return;
            }
        }
        cout << "Alice" << '\n';
    }
}

int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
