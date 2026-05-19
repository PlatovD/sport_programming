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

    int k1, m, k2, p2, n2;
    cin >> k1 >> m >> k2 >> p2 >> n2;

    vector<int> possible_p, possible_n;
    for (int flats_per_floor = 1; flats_per_floor < 1e6 + 1; flats_per_floor++) {
        int entrance2 = (k2 + m * flats_per_floor - 1) / (m * flats_per_floor);
        int floor2 = (k2 - (entrance2 - 1) * m * flats_per_floor + flats_per_floor - 1) / flats_per_floor;
        if (entrance2 == p2 && floor2 == n2) {
            int entrance1 = (k1 + m * flats_per_floor - 1) / (m * flats_per_floor);
            int floor1 = (k1 - (entrance1 - 1) * m * flats_per_floor + flats_per_floor - 1) / flats_per_floor;
            possible_p.push_back(entrance1);
            possible_n.push_back(floor1);
        }
    }

    if (possible_n.empty()) {
        cout << -1 << ' ' << -1 << '\n';
        return 0;
    }

    bool p1_unique = true, n1_unique = true;
    int p1 = possible_p.front(), n1 = possible_n.front();
    for (int i = 1; i < possible_n.size(); i++) {
        if (possible_n[i] != n1) {
            n1_unique = false;
        }
        if (possible_p[i] != p1) {
            p1_unique = false;
        }
    }
    cout << (p1_unique ? p1 : 0) << ' ' << (n1_unique ? n1 : 0) << '\n';
}
