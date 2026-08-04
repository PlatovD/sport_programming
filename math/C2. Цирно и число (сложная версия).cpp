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

ll fast_pow(ll num, ll power) {
    ll res = 1;
    while (power > 0) {
        if (power & 1) res *= num;
        num *= num;
        power /= 2;
    }
    return res;
}

ll build_one_rank_less_biggest(vector<ll> &digits_of_original, set<ll> &allowed, ll original_A) {
    if (digits_of_original.size() == 1)
        return *allowed.rbegin();

    ll power = 1;
    ll res = 0;
    auto it = allowed.rbegin();
    for (int i = 0; i < digits_of_original.size() - 1; i++) {
        res += *it * power;
        power *= 10;
    }
    return abs(res - original_A);
}

ll build_one_rank_more_lowest(vector<ll> &digits_of_original, set<ll> &allowed, ll original_A) {
    ll power = 1;
    ll res = 0;
    auto it = allowed.begin();
    for (int i = 0; i < digits_of_original.size() + 1; i++) {
        if (i == digits_of_original.size() && *it == 0) it = next(it);
        res += *it * power;
        power *= 10;
    }
    return abs(res - original_A);
}

ll build_same_rank_best(vector<ll> &digits_of_original, set<ll> &allowed, ll original_A) {
    ll min_diff = -1;
    ll current_prefix = 0;

    for (int i = (int) digits_of_original.size() - 1; i > -1; i--) {
        ll curr_digit = digits_of_original[i];
        ll power = fast_pow(10, i);

        auto it_low = allowed.lower_bound(curr_digit);
        if (it_low != allowed.begin()) {
            it_low = prev(it_low);
            if (!(i == (int) digits_of_original.size() - 1 && *it_low == 0 && digits_of_original.size() > 1)) {
                ll cand = current_prefix + *it_low * power;
                ll rem_power = power / 10;
                for (int j = i - 1; j > -1; j--) {
                    cand += *allowed.rbegin() * rem_power;
                    rem_power /= 10;
                }
                ll diff = abs(original_A - cand);
                if (min_diff == -1 || diff < min_diff) min_diff = diff;
            }
        }

        auto it_high = allowed.upper_bound(curr_digit);
        if (it_high != allowed.end()) {
            ll cand = current_prefix + *it_high * power;
            ll rem_power = power / 10;
            for (int j = i - 1; j > -1; j--) {
                cand += *allowed.begin() * rem_power;
                rem_power /= 10;
            }
            ll diff = abs(original_A - cand);
            if (min_diff == -1 || diff < min_diff) min_diff = diff;
        }

        if (!allowed.count(curr_digit)) {
            break;
        }

        current_prefix += curr_digit * power;

        if (i == 0) {
            min_diff = 0;
        }
    }

    return min_diff == -1 ? INT64_MAX : min_diff;
}


void solve() {
    ll a, n;
    cin >> a >> n;

    set<ll> allowed;
    ll num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        allowed.insert(num);
    }

    if (allowed.size() == 1 && *allowed.begin() == 0) {
        cout << a << '\n';
        return;
    }

    vector<ll> digits_of_original;
    ll tmp_a = a;
    do {
        digits_of_original.push_back(tmp_a % 10);
        tmp_a /= 10;
    } while (tmp_a > 0);


    cout << min(
        min(build_one_rank_less_biggest(digits_of_original, allowed, a),
            build_one_rank_more_lowest(digits_of_original, allowed, a)),
        build_same_rank_best(digits_of_original, allowed, a)) << '\n';
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
    cin >> t;
    while (t--) {
        solve();
    }
}
