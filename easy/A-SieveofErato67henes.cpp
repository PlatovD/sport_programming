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
#include <functional>
#include <memory>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool was_67 = false, was_1 = false;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            if (num == 67) {
                was_67 = true;
            }
        }
        if (was_67) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}
