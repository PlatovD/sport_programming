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

    int n, m, k;
    cin >> n >> m >> k;

    vector v(n + 2, vector<int>(m + 2));
    int p, q;
    for (int i = 0; i < k; i++) {
        cin >> p >> q;
        v[p][q] = -1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == -1) continue;
            int cnt_bombs_nearby = 0;
            for (int y = i - 1; y < i + 2; y++) {
                for (int x = j - 1; x < j + 2; x++) {
                    if (i == y && j == x) continue;
                    if (v[y][x] == -1) cnt_bombs_nearby++;
                }
            }
            v[i][j] = cnt_bombs_nearby;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == -1)
                cout << '*' << ' ';
            else cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}
