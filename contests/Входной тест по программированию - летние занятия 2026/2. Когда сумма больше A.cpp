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

    int A;
    cin >> A;

    vector<int> v;
    int num;
    cin >> num;
    while (num != 0) {
        v.emplace_back(num);
        cin >> num;
    }

    int current_sum = 0;
    for (int i = 0; i < v.size(); i++) {
        current_sum += v[i];
        if (current_sum > A) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}
