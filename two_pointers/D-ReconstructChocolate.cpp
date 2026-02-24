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

    int H, W, N;
    cin >> H >> W >> N;

    vector<int> h(N);
    vector<int> w(N);

    for (int i = 0; i < N; i++) cin >> h[i] >> w[i];

    vector<int> index_h_ord(N);
    iota(index_h_ord.begin(), index_h_ord.end(), 0);
    sort(index_h_ord.begin(), index_h_ord.end(), [&h](int a, int b) -> bool {
        return h[b] < h[a];
    });

    vector<int> index_w_ord(N);
    iota(index_w_ord.begin(), index_w_ord.end(), 0);
    sort(index_w_ord.begin(), index_w_ord.end(), [&w](int a, int b) -> bool {
        return w[b] < w[a];
    });

    vector<int> ans_x(N), ans_y(N);
    vector<int> used(N, false);

    auto h_it = index_h_ord.begin();
    auto w_it = index_w_ord.begin();
    int n = N;
    while (n-- > 0) {
        while (used[*h_it]) ++h_it;
        while (used[*w_it]) ++w_it;
        if (h[*h_it] == H) {
            int i = *h_it;
            used[i] = true;
            ans_x[i] = W - w[i] + 1;
            ans_y[i] = H - h[i] + 1;
            W -= w[i];
        } else {
            int i = *w_it;
            used[i] = true;
            ans_x[i] = W - w[i] + 1;
            ans_y[i] = H - h[i] + 1;
            H -= h[i];
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans_y[i] << ' ' << ans_x[i] << '\n';
    }
}
