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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n * n + 1);
        int num;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> num;
                v[num]++;
            }
        }

        int max_aval_one_num = n * n - n;
        bool is_good = true;
        for (int i = 0; i < n * n + 1; i++) {
            if (v[i] > max_aval_one_num) {
                is_good = false;
                break;
            }
        }
        if (is_good) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
