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

vector<bool> build_sieve_of_eratosthenes() {
    vector sieve(1e6 + 1, true);
    for (int i = 2; i < 1e6 + 1; i++) {
        if (!sieve[i]) continue;
        for (int j = i * 2; j < 1e6 + 1; j += i) {
            sieve[j] = false;
        }
    }
    return sieve;
}


// шаблон
// отсортированно сразу - победа Боба
// в списке есть простое число, которое больше, чем идущее дальше не простое значение - победа Алисы
//
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

        bool is_good = true;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                is_good = false;
                break;
            }
        }

        if (is_good) {
            cout << "Bob" << '\n';
        }

        vector<bool> sieve = build_sieve_of_eratosthenes();

        
    }
}
