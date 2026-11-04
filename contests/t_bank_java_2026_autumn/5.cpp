#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll count_pairs(const vector<ll> &a, ll mid) {
    ll count = 0;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        ll x = a[i];

        int left = i + 1;
        int right = n - 1;
        int pos = -1;

        if (x > 0) {
            while (left <= right) {
                int m = left + (right - left) / 2;
                if (x * a[m] <= mid) {
                    pos = m;
                    left = m + 1;
                } else {
                    right = m - 1;
                }
            }
            if (pos != -1) {
                count += pos - i;
            }
        } else if (x < 0) {
            while (left <= right) {
                int m = left + (right - left) / 2;
                if (x * a[m] <= mid) {
                    pos = m;
                    right = m - 1;
                } else {
                    left = m + 1;
                }
            }
            if (pos != -1) {
                count += n - pos;
            }
        } else {
            if (mid >= 0) {
                count += n - 1 - i;
            }
        }
    }
    return count;
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll p1 = a[0] * a[1];
    ll p2 = a[n - 1] * a[n - 2];
    ll p3 = a[0] * a[n - 1];

    ll low = min({p1, p2, p3});
    ll high = max({p1, p2, p3});
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (count_pairs(a, mid) >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
