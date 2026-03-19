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
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<int> a;
        int l = 0;
        int r = 1;
        a.push_back(b[0]);
        while (r < n) {
            if (b[r] < b[l]) {
                a.push_back(b[r]);
            }
            a.push_back(b[r]);
            l++;
            r++;
        }
        cout << a.size() << '\n';
        for (int i: a) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}
