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
    for (int q = 0; q < t; q++) {
        int n;
        cin >> n;
        int polykarp_power, polykarp_endurance;
        cin >> polykarp_power >> polykarp_endurance;
        bool can_win = true;
        int power, endurance;
        for (int i = 1; i < n; i++) {
            cin >> power >> endurance;
            if (power >= polykarp_power && endurance >= polykarp_endurance) can_win = false;
        }
        if (can_win)
            cout << polykarp_power << '\n';
        else cout << -1 << '\n';
    }
}
