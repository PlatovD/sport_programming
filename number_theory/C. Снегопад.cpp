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

        vector<vector<int> > matrix(4);
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            if (num % 6 == 0) {
                matrix[0].push_back(num);
            } else if (num % 3 == 0) {
                matrix[1].push_back(num);
            } else if (num % 2 == 0) {
                matrix[2].push_back(num);
            } else {
                matrix[3].push_back(num);
            }
        }

        vector indices = {2, 3, 1, 0};
        for (auto i: indices) {
            for (int nu: matrix[i]) {
                cout << nu << ' ';
            }
        }
        cout << endl;
    }
}
