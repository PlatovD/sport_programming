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
        int n, k;
        cin >> n >> k;
        vector<string> lines(k);
        for (auto &el: lines) cin >> el;

        // первым этапом пройдусь и на каждую позицию сделаю массив из 26 букв по их присутствию
        vector existing_chars_on_positions(n, vector<bool>(26));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                existing_chars_on_positions[i][lines[j][i] - 'a'] = true;
            }
        }

        // буду подбирать минимальный возможный step
        int res_step = n;
        vector<char> res_vector;
        for (int step = 1; step <= n; step++) {
            if (n % step != 0)
                continue;
            int cnt_chars_required_for_step = step;
            vector<char> chars(cnt_chars_required_for_step);
            // перебор позиций начала текущей буквы
            bool is_bad_step_generally = false;
            for (int s = 0; s < cnt_chars_required_for_step; s++) {
                // ищу на все позции с началом в s и шагом step нужную букву
                bool is_found = false;
                for (int ch = 0; ch < 26; ch++) {
                    bool is_bad = false;
                    for (int pos = s; pos < n; pos += step) {
                        if (!existing_chars_on_positions[pos][ch]) {
                            is_bad = true;
                            break;
                        }
                    }
                    if (is_bad) {
                        continue;
                    }
                    chars[s] = static_cast<char>('a' + ch);
                    is_found = true;
                    break;
                }
                if (!is_found) {
                    is_bad_step_generally = true;
                    break;
                }
            }
            if (is_bad_step_generally) continue;
            res_step = step;
            res_vector = chars;
            break;
        }

        for (int i = 0; i < n / res_step; i += 1) {
            for (int j = 0; j < res_step; j++) {
                cout << res_vector[j];
            }
        }
        cout << '\n';
    }
}
