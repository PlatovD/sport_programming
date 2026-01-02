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
    while (t--) {
        int n;
        cin >> n;
        map<int, int> entry;
        vector<int> b(n);
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            b[i] = num;
            if (entry.find(num) != entry.end()) {
                entry[num]++;
            } else {
                entry[num] = 1;
            }
        }
        int cur_n = 0;
        bool is_good = true;
        for (auto en: entry) {
            if (en.second % en.first != 0) {
                is_good = false;
                break;
            }
            cur_n += en.second;
        }
        if (cur_n > n) {
            is_good = false;
        }
        if (!is_good) {
            cout << -1 << '\n';
            continue;
        }

        int cur_num = 1;
        map<int, int> what_put;
        for (int i = 0; i < n; i++) {
            if (what_put.find(b[i]) != what_put.end()) {
                cout << what_put[b[i]] << ' ';
                entry[b[i]]--;
                if (entry[b[i]] % b[i] == 0) {
                    what_put[b[i]] = cur_num;
                    cur_num++;
                }
            } else {
                what_put[b[i]] = cur_num;
                cout << cur_num << ' ';
                cur_num++;
                entry[b[i]]--;
                if (entry[b[i]] % b[i] == 0) {
                    what_put[b[i]] = cur_num;
                    cur_num++;
                }
            }
        }
        cout << '\n';
    }
}
