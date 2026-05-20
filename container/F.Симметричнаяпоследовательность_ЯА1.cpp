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

void print_ans(int additional, vector<int> &v) {
    cout << additional << '\n';
    for (int i = additional - 1; i > -1; i--) {
        cout << v[i] << " ";
    }
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

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int addition = 0; addition < n; addition++) {
        bool is_good = true;
        int l = 0;
        int r = n - 1 + addition;
        while (l < r) {
            if (n <= r) {
                if (v[l] != v[n - 1 + addition - r]) {
                    is_good = false;
                    break;
                }
            } else {
                if (v[l] != v[r]) {
                    is_good = false;
                    break;
                }
            }
            l++;
            r--;
        }
        if (is_good) {
            print_ans(addition, v);
            return 0;
        }
    }
}
