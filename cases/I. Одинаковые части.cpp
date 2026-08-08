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
#define ld long double
// #define _DEBUG
using namespace std;

ll MOD = 1e9 + 7;


void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int elements, groups, len;

    // разбиения, когда все удаления внутри
    elements = n - k;
    groups = k + 1;
    if (elements > 0 && elements % groups == 0) {
        bool good = true;
        len = elements / groups;
        string sample = s.substr(0, len);
        for (int i = 0; i < n; i += len + 1) {
            if (i + len > n || sample != s.substr(i, len)) {
                good = false;
                break;
            }
        }

        if (good) {
            cout << "YES";
            return;
        }
    }

    // когда первое удаление снаружи слева
    elements = n - k;
    groups = k;
    if (elements > 0 && elements % groups == 0) {
        bool good = true;
        len = elements / groups;
        string sample = s.substr(1, len);
        for (int i = 1; i < n; i += len + 1) {
            if (i + len > n || sample != s.substr(i, len)) {
                good = false;
                break;
            }
        }

        if (good) {
            cout << "YES";
            return;
        }
    }

    // когда ласт удаление снаружи справа
    elements = n - k;
    groups = k;
    if (elements > 0 && elements % groups == 0) {
        bool good = true;
        len = elements / groups;
        string sample = s.substr(0, len);
        for (int i = 0; i < n; i += len + 1) {
            // <-- Изменили на i < n
            if (i + len > n || sample != s.substr(i, len)) {
                good = false;
                break;
            }
        }

        if (good) {
            cout << "YES";
            return;
        }
    }

    // когда два удаления по краям
    if (k > 1) {
        elements = n - k;
        groups = k - 1;
        if (elements > 0 && elements % groups == 0) {
            bool good = true;
            len = elements / groups;
            string sample = s.substr(1, len);
            for (int i = 1; i < n; i += len + 1) {
                if (i + len > n || sample != s.substr(i, len)) {
                    good = false;
                    break;
                }
            }

            if (good) {
                cout << "YES";
                return;
            }
        }
    }

    cout << "NO";
}

int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
