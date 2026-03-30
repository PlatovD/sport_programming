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
        int n, h, k;
        cin >> n >> h >> k;

        ll total_time = 0;

        vector<ll> damages(n);
        vector<ll> prefixes(n + 1);

        prefixes[0] = 0;
        ll total_damage = 0;
        for (int i = 0; i < n; i++) {
            cin >> damages[i];
            total_damage += damages[i];
            prefixes[i + 1] = prefixes[i] + damages[i];
        }

        // для каждого буду знать меньший из пройденных
        vector<ll> mins(n);
        mins[0] = damages[0];
        for (int i = 1; i < n; i++) {
            mins[i] = min(mins[i - 1], damages[i]);
        }

        // для каждого буду знать боольший из тех, что справа
        vector<ll> maxes(n);
        maxes[n - 1] = 0;
        for (int i = n - 2; i > -1; i--) {
            maxes[i] = max(damages[i + 1], maxes[i + 1]);
        }


        ll magazines = h / total_damage;
        ll reminder = h - total_damage * magazines;
        total_time += magazines * n + k * (reminder == 0 ? max(magazines - 1, 0ll) : magazines);

        // тут как раз надо хитро максимизировать начальную часть массива. Я буду держать для каждого индекса, какие есть после него максимальные элементы, а так же мне нужны перфиксные суммы. Можно бин поиском находить необходимое минималньое число элементов. При этом в бин поиске сделать рассчет возможности через замену минимального из взятых элементов на то, что будет в максимуме по индексу из последнего невзятого
        int last_good = 0;
        if (reminder > 0) {
            int l = 1;
            int r = n;

            while (l <= r) {
                int m = l + (r - l) / 2;
                if (max(prefixes[m] - mins[m - 1] + maxes[m - 1], prefixes[m]) >= reminder) {
                    last_good = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }

        cout << total_time + last_good << '\n';
    }
}
