#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element {
    int value;
    int origin_idx;
};

bool compareElements(const Element& a, const Element& b) {
    return a.value < b.value;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<Element> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].value;
        a[i].origin_idx = i;
    }

    stable_sort(a.begin(), a.end(), compareElements);

    int max_needed_k = 0;

    for (int current_idx = 0; current_idx < n; current_idx++) {
        int origin_idx = a[current_idx].origin_idx;
        int xor_val = origin_idx ^ current_idx;

        if (xor_val > 0) {
            int highest_bit = 1;
            while ((highest_bit << 1) <= xor_val) {
                highest_bit <<= 1;
            }

            max_needed_k = max(max_needed_k, highest_bit);
        }
    }

    cout << max_needed_k << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
