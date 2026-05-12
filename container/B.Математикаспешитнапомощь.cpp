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

    string s;
    cin >> s;
    vector<int> nums;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '3') nums.push_back(3);
        if (s[i] == '2') nums.push_back(2);
        if (s[i] == '1') nums.push_back(1);
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++) {
        cout << nums[i] << "+";
    }
    cout << nums[nums.size() - 1];
}
