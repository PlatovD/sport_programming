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

    int a, b, n, m;
    cin >> a >> b >> n >> m;

    int min_first_path_time = n + a * (n - 1);
    int max_first_path_time = n + a * (n - 1) + 2 * a;

    int min_second_path_time = m + b * (m - 1);
    int max_second_path_time = m + b * (m - 1) + 2 * b;

    if (max_first_path_time < min_second_path_time || max_second_path_time < min_first_path_time) {
        cout << -1 << '\n';
    } else
        cout << max(min_first_path_time, min_second_path_time) << ' ' << min(max_first_path_time, max_second_path_time)
                <<
                endl;
}
