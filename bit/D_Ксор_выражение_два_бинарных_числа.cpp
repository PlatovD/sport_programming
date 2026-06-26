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

ll count_1(string s) {
    ll res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') res++;
    }
    return res;
}

string s_xor(string s1, string s2) {
    int n = s1.length();
    string res;
    res.reserve(n);
    for (int i = 0; i < n; i++) {
        res.push_back(s1[i] == s2[i] ? '0' : '1');
    }
    return res;
}

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
        int n, k;
        cin >> n >> k;
        string s1, s2;
        cin >> s1 >> s2;

        map<pair<string, string>, int> counts_pairs;
        counts_pairs[s1 < s2 ? pair(s1, s2) : pair(s2, s1)] = 1;

        map<string, ll> counts_nums;
        counts_nums[s1] += 1;
        counts_nums[s2] += 1;

        for (int i = 0; i < k; i++) {
            map<pair<string, string>, int> delta;

            for (auto kv: counts_pairs) {
                int factor = kv.second;
                if (factor <= 0) continue;

                string first_num = kv.first.first;
                string second_num = kv.first.second;
                string res = s_xor(first_num, second_num);
                counts_nums[res] += factor;

                delta[{first_num, second_num}] -= factor;

                if (first_num > res) {
                    delta[{res, first_num}] += factor;
                } else {
                    delta[{first_num, res}] += factor;
                }

                if (second_num > res) {
                    delta[{res, second_num}] += factor;
                } else {
                    delta[{second_num, res}] += factor;
                }
            }

            for (auto kv: delta) {
                counts_pairs[kv.first] += kv.second;
            }
        }

        ll total = 0;
        for (auto kv: counts_nums) {
            ll cnt_1 = count_1(kv.first);
            ll cnt_0 = kv.first.size() - cnt_1;
            total += kv.second * cnt_0 * cnt_1;
        }
        cout << total << endl;
    }
}
