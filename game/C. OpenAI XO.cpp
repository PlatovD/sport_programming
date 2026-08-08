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

bool check_win(vector<int> &field, int turn) {
    if (field[0] == turn && field[1] == turn && field[2] == turn) return true;
    if (field[3] == turn && field[4] == turn && field[5] == turn) return true;
    if (field[6] == turn && field[7] == turn && field[8] == turn) return true;

    if (field[0] == turn && field[3] == turn && field[6] == turn) return true;
    if (field[1] == turn && field[4] == turn && field[7] == turn) return true;
    if (field[2] == turn && field[5] == turn && field[8] == turn) return true;

    if (field[0] == turn && field[4] == turn && field[8] == turn) return true;
    if (field[2] == turn && field[4] == turn && field[6] == turn) return true;

    return false;
}

int minimax(vector<int> &field, bool my_turn) {
    if (check_win(field, 1)) return 1;
    if (check_win(field, -1)) return -1;

    bool has_move = false;
    for (int i = 0; i < 9; i++)
        if (field[i] == 0) has_move = true;


    if (!has_move)
        return 0;

    if (my_turn) {
        int best_score = -100;
        for (int i = 0; i < 9; i++) {
            // если могу победить то беру победную ветку рекурсии
            if (field[i] == 0) {
                field[i] = 1;
                best_score = max(best_score, minimax(field, false));
                field[i] = 0;
            }
        }
        return best_score;
    }
    int best_score = 100;
    for (int i = 0; i < 9; i++) {
        // когда есть шанс сделать из текущего хода поражение - противник это делает и уже эта ветвь рекурсии отстойная дл текущего игрока
        if (field[i] == 0) {
            field[i] = -1;
            best_score = min(best_score, minimax(field, true));
            field[i] = 0;
        }
    }
    return best_score;
}


void solve() {
    vector field(9, 0);

    // просчитаю фулл всю игру наперед

    char start;
    cin >> start;
    if (start == 'X') {
        field[1 * 3 + 1] = 1;
        cout << 2 << ' ' << 2 << '\n';
        cout.flush();
    }


    int row, col;
    string s;
    while (true) {
        cin >> s;
        if (s.empty()) return;
        if (s == "WIN" || s == "LOSE" || s == "DRAW") return;
        row = s[0] - '1';
        cin >> s;
        col = s[0] - '1';

        field[row * 3 + col] = -1;

        int best_step = -100;
        int best_index = -1;
        for (int i = 0; i < 9; i++) {
            if (field[i] != 0) continue;

            field[i] = 1;
            int move_val = minimax(field, false);
            field[i] = 0;

            if (move_val > best_step) {
                best_step = move_val;
                best_index = i;
            }
        }

        if (best_index != -1) {
            field[best_index] = 1;
            cout << best_index / 3 + 1 << ' ' << best_index % 3 + 1 << '\n';
            cout.flush();
        }
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
    // cin >> t;
    while (t--) {
        solve();
    }
}
