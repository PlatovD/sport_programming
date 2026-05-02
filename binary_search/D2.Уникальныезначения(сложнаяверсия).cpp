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

int n;

int was_border_left(int r) {
    int req_res;
    string req = "? " + to_string(r + 1);
    for (int i = 0; i <= r; i++) {
        req += " " + to_string(i + 1);
    }
    cout << req << endl;
    cin >> req_res;
    cout.flush();
    return req_res;
}

int was_border_right(int l) {
    int req_res;
    string req = "? " + to_string(2 * n - l + 1);
    for (int i = 2 * n; i >= l; i--) {
        req += " " + to_string(i + 1);
    }
    cout << req << endl;
    cin >> req_res;
    cout.flush();
    return req_res;
}

int was_el_center(int left_b, int right_b, int n) {
    int req_res;
    string req = "? " + to_string(n - left_b + 2) + " " + to_string(left_b + 1) + " " + to_string(right_b + 1);
    for (int i = left_b + 1; i <= n; i++) {
        req += " " + to_string(i + 1);
    }
    cout << req << endl;
    cin >> req_res;
    cout.flush();
    return req_res;
}

int find_right_border(int n) {
    int right_border = -1;

    int l = 0;
    int r = n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (was_border_left(m) % 2 == (m + 1) % 2) {
            l = m + 1;
        } else {
            right_border = m;
            r = m - 1;
        }
    }
    return right_border;
}

int find_left_border(int n) {
    int left_border = -1;

    int l = 0;
    int r = n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (was_border_right(m) % 2 != (m + 1) % 2) {
            left_border = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return left_border;
}

int find_center_el(int left_b, int right_b) {
    int center_el = -1;

    int l = left_b;
    int r = right_b;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (was_el_center(left_b, right_b, m) % 2 != (m - left_b) % 2) {
            center_el = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return center_el;
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

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cout.flush();

        int left_index = find_left_border(2 * n);
        int right_index = find_right_border(2 * n);
        int center_index = find_center_el(left_index, right_index);
        cout << "! " << left_index + 1 << " " << center_index + 1 << " " << right_index + 1 << endl;
        cout.flush();
    }
}
