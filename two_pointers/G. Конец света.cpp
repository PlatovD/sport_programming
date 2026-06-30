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

    ll n, m, k, t;
    cin >> n >> m >> k >> t;

    vector<ll> people(n);
    vector<ll> shelters(m);

    for (int i = 0; i < n; i++) cin >> people[i];
    for (int i = 0; i < m; i++) cin >> shelters[i];

    sort(people.begin(), people.end());
    sort(shelters.begin(), shelters.end());

    vector<ll> guests(m, 0);
    int people_ptr = 0, shelters_ptr = 0;
    while (people_ptr < n && shelters_ptr < m) {
        if (guests[shelters_ptr] == k) {
            shelters_ptr++;
            continue;
        }

        if (abs(people[people_ptr] - shelters[shelters_ptr]) > t) {
            if (people[people_ptr] < shelters[shelters_ptr]) {
                people_ptr++;
            } else {
                shelters_ptr++;
            }
        } else {
            guests[shelters_ptr]++;
            people_ptr++;
        }
    }

    ll total = 0;
    for (auto num: guests)
        total += num;
    cout << total << '\n';
}
