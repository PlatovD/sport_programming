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

    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    int min_A = min(A, min(B, C));
    int min_B = A + B + C - min_A - max(max(A, B), C);

    if (min_A <= min(D, E) && min_B <= max(D, E)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}
