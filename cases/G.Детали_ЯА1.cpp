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

    int N, K, M;
    cin >> N >> K >> M;

    int total = 0;
    int reminder = N;
    while (true) {
        int cnt_blanks = reminder / K;
        if (cnt_blanks == 0) {
            break;
        }
        reminder -= cnt_blanks * K;
        int cnt_details_from_one_blank = K / M;
        int cnt_reminder_from_one_blank = K % M;
        if (cnt_details_from_one_blank == 0) {
            break;
        }
        total += cnt_details_from_one_blank * cnt_blanks;
        reminder += cnt_reminder_from_one_blank * cnt_blanks;
    }
    cout << total << endl;
}
