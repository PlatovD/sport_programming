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
        int n, k;
        cin >> n >> k;
        vector<string> lines(n);
        for (auto &el: lines) cin >> el;

        // первым этапом пройдусь и на каждую позицию сделаю массив из 26 букв по их присутствию
        vector existing_chars_on_positions(n, vector<bool>(26));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                existing_chars_on_positions[i][lines[i][j] - 'a'] = true;
            }
        }


    }
}
