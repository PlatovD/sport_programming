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

struct segment {
    ll left_border, right_border;
    ll height;
    ll total_after = 0;
};

int find_border(vector<segment> &prefix, ll border) {
    int l = 0, r = prefix.size() - 1;
    int res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (prefix[mid].left_border <= border && prefix[mid].right_border > border) {
            res = mid;
            break;
        }
        if (prefix[mid].left_border > border) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

// первый сегмент у которого height больше, чем уже удаленное
int find_border_by_height(vector<segment> &prefix, ll height) {
    int l = 0, r = prefix.size() - 1;
    int res = 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (prefix[mid].height > height) {
            l = mid + 1;
        } else {
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}

void solve() {
    ll s, q;
    cin >> s >> q;

    vector<pair<ll, ll> > all_possible_rects;
    for (ll i = 1; i * i <= s; i++)
        if (s % i == 0)
            all_possible_rects.push_back({i, s / i});

    for (int i = all_possible_rects.size() - 1; i >= 0; i--) {
        if (all_possible_rects[i].first == all_possible_rects[i].second) continue;
        all_possible_rects.push_back({all_possible_rects[i].second, all_possible_rects[i].first});
    }

    vector<segment> prefix(all_possible_rects.size());

    ll current_x = 0;
    for (int i = 0; i < all_possible_rects.size(); i++) {
        ll width = all_possible_rects[i].first, height = all_possible_rects[i].second;
        prefix[i] = {current_x, width, height};
        current_x = width;
    }

    for (int i = prefix.size() - 2; i >= 0; i--) {
        prefix[i].total_after = prefix[i + 1].total_after + prefix[i + 1].height * (
                                    prefix[i + 1].right_border - prefix[i + 1].left_border);
    }

    ll pos = prefix[0].total_after + (prefix[0].right_border - prefix[0].left_border) * prefix[0].height;


    while (q--) {
        ll x, y;
        cin >> x >> y;
        ll total = pos;

        int right_border_segment_index = find_border(prefix, x), top_border_segment_index = find_border(prefix, y);

        if (top_border_segment_index != -1) {
            total -= prefix[top_border_segment_index].total_after;
            total -= prefix[top_border_segment_index].height * (prefix[top_border_segment_index].right_border - y);
        }

        int right_border_segment_index_by_height = find_border_by_height(prefix, y);
        if (top_border_segment_index != -1 && right_border_segment_index != -1 && right_border_segment_index_by_height >
            right_border_segment_index) {
            total -= y * abs(x - prefix[right_border_segment_index_by_height].left_border);
            total -= prefix[right_border_segment_index_by_height - 1].total_after;
        } else if (right_border_segment_index != -1) {
            total -= prefix[right_border_segment_index].total_after;
            total -= prefix[right_border_segment_index].height * (prefix[right_border_segment_index].right_border - x);
        }


        cout << total << '\n';
    }
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
