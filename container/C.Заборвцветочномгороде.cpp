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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        map<int, int> number_of_layers;
        int last_layer_a = 0;
        int current_layer_length = n;
        for (int i = n - 1; i > -1; i--) {
            if (a[i] != last_layer_a) {
                number_of_layers[current_layer_length] = a[i] - last_layer_a;
                last_layer_a = a[i];
            }
            current_layer_length--;
        }

        bool is_bad = false;
        for (int i = 0; i < n; i++) {
            if (number_of_layers.find(a[i]) == number_of_layers.end() || number_of_layers[a[i]] < 1) {
                is_bad = true;
                break;
            }
            number_of_layers[a[i]]--;
        }
        if (is_bad) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
}
