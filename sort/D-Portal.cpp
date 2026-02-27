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
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> outside;
        vector<int> between;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            if (i >= x && i < y) {
                between.push_back(num);
            } else {
                outside.push_back(num);
            }
        }

        int best_between_index = 0;
        int outside_n = outside.size();
        int between_n = between.size();

        for (int i = 0; i < between_n; i++) {
            if (between[i] < between[best_between_index]) {
                best_between_index = i;
            }
        }


        int last_between = between_n;
        int i = 0;
        while (i < outside_n && outside[i] < between[best_between_index]) {
            cout << outside[i] << ' ';
            i++;
        }
        while (last_between) {
            cout << between[best_between_index % between_n] << ' ';
            best_between_index++;
            last_between--;
        }
        while (i < outside_n) {
            cout << outside[i] << ' ';
            i++;
        }
        cout << '\n';
    }
}
