#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;

    int num_players = 1 << n;

    vector c(num_players, vector<ll>(n + 1, 0));
    for (int i = 0; i < num_players; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    vector<ll> f(num_players, 0);

    for (int k = 1; k <= n; k++) {
        int len = 1 << k;
        int half = 1 << (k - 1);

        for (int block_start = 0; block_start < num_players; block_start += len) {
            ll best_L = -1;
            ll best_R = -1;

            for (int i = block_start; i < block_start + half; i++) {
                best_L = max(best_L, f[i] + c[i][k - 1]);
            }

            for (int j = block_start + half; j < block_start + len; j++) {
                best_R = max(best_R, f[j] + c[j][k - 1]);
            }

            for (int i = block_start; i < block_start + half; i++) {
                f[i] += best_R;
            }

            for (int j = block_start + half; j < block_start + len; j++) {
                f[j] += best_L;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < num_players; i++) {
        ans = max(ans, f[i] + c[i][n]);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
