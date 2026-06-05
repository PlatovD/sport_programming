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
        ll n, x, s;
        cin >> n >> x >> s;
        string u;
        cin >> u;

        ll a_opened = 0;
        ll extraverts_places = 0;
        ll free_tables = x;

        ll total = 0;
        for (int i = 0; i < n; i++) {
            if (u[i] == 'A') {
                if (extraverts_places > 0) {
                    extraverts_places--;
                    a_opened++;
                } else {
                    free_tables--;
                    extraverts_places += s - 1;
                }
                total++;
            }
            if (u[i] == 'I') {
                if (free_tables == 0)continue;
                free_tables--;
                extraverts_places += s - 1;
                total++;
            }
            if (u[i] == 'E') {
                if (extraverts_places > 0) {
                    extraverts_places--;
                    total++;
                } else {
                    if (free_tables && a_opened) {
                        free_tables--;
                        a_opened--;
                        extraverts_places += s;
                        extraverts_places--;
                        total++;
                    }
                }
            }
        }
        cout << min(total, x * s) << endl;
    }
}
