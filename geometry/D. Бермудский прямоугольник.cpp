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

#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
#define ld long double
using namespace std;

ll MOD = 1e9 + 7;

struct segment {
    ll left_border, right_border;
    ll height;
    ll total_after = 0;
};

vector<pair<ll, ll> > all_possible_rects;
vector<segment> prefix;
vector<ll> left_borders;
vector<ll> heights;

const int MAX_N = 1735;
vector<ll> memo_pair;
vector<ll> memo_x;
vector<ll> memo_y;

void solve() {
    ll s, q;
    cin >> s >> q;

    all_possible_rects.clear();
    prefix.clear();
    left_borders.clear();
    heights.clear();

    for (int i = 1; (ll) i * i <= s; i++)
        if (s % i == 0)
            all_possible_rects.push_back({i, s / i});

    for (int i = (int) all_possible_rects.size() - 1; i >= 0; i--) {
        if (all_possible_rects[i].first == all_possible_rects[i].second) continue;
        all_possible_rects.push_back({all_possible_rects[i].second, all_possible_rects[i].first});
    }

    int n = (int) all_possible_rects.size();
    prefix.resize(n);

    ll current_x = 0;
    for (int i = 0; i < n; i++) {
        ll width = all_possible_rects[i].first, height = all_possible_rects[i].second;
        prefix[i] = {current_x, width, height};
        left_borders.push_back(current_x);
        heights.push_back(height);
        current_x = width;
    }

    for (int i = n - 2; i >= 0; i--) {
        prefix[i].total_after = prefix[i + 1].total_after + prefix[i + 1].height * (
                                    prefix[i + 1].right_border - prefix[i + 1].left_border);
    }

    ll pos = prefix[0].total_after + (prefix[0].right_border - prefix[0].left_border) * prefix[0].height;

    memo_pair.assign((n + 2) * MAX_N, -1);
    memo_x.assign(n + 2, -1);
    memo_y.assign(n + 2, -1);

    while (q--) {
        ll x, y;
        cin >> x >> y;
        ll total = pos;

        auto it_x = upper_bound(left_borders.data(), left_borders.data() + left_borders.size(), x);
        int right_border_segment_index = (int) (it_x - left_borders.data()) - 1;
        if (right_border_segment_index >= 0 && prefix[right_border_segment_index].right_border <= x) {
            right_border_segment_index = -1;
        }

        auto it_y = upper_bound(left_borders.data(), left_borders.data() + left_borders.size(), y);
        int top_border_segment_index = (int) (it_y - left_borders.data()) - 1;
        if (top_border_segment_index >= 0 && prefix[top_border_segment_index].right_border <= y) {
            top_border_segment_index = -1;
        }

        int cx = right_border_segment_index + 1;
        int cy = top_border_segment_index + 1;

        ll sub_y = 0;
        if (top_border_segment_index != -1) {
            if (memo_y[cy] != -1) {
                sub_y = memo_y[cy];
            } else {
                sub_y = prefix[top_border_segment_index].total_after;
                memo_y[cy] = sub_y;
            }
            sub_y += prefix[top_border_segment_index].height * (prefix[top_border_segment_index].right_border - y);
            total -= sub_y;
        }

        auto it = lower_bound(heights.data(), heights.data() + heights.size(), y, greater<ll>());
        int right_border_segment_index_by_height = (int) (it - heights.data());

        if (top_border_segment_index != -1 && right_border_segment_index != -1 && right_border_segment_index_by_height >
            right_border_segment_index) {
            int flat_idx = cx * MAX_N + cy;
            ll sub_intersection = 0;
            if (memo_pair[flat_idx] != -1) {
                sub_intersection = memo_pair[flat_idx];
            } else {
                sub_intersection = prefix[right_border_segment_index_by_height - 1].total_after;
                memo_pair[flat_idx] = sub_intersection;
            }
            sub_intersection += y * (prefix[right_border_segment_index_by_height].left_border - x);
            total -= sub_intersection;
        } else if (right_border_segment_index != -1) {
            ll sub_x = 0;
            if (memo_x[cx] != -1) {
                sub_x = memo_x[cx];
            } else {
                sub_x = prefix[right_border_segment_index].total_after;
                memo_x[cx] = sub_x;
            }
            sub_x += prefix[right_border_segment_index].height * (prefix[right_border_segment_index].right_border - x);
            total -= sub_x;
        }

        cout << total << '\n';
    }
}

int main() {
#if defined _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    all_possible_rects.reserve(2000);
    prefix.reserve(2000);
    left_borders.reserve(2000);
    heights.reserve(2000);

    memo_pair.reserve(MAX_N * MAX_N);
    memo_x.reserve(MAX_N);
    memo_y.reserve(MAX_N);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
