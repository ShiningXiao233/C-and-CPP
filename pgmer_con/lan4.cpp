#include <iostream>

using namespace std;

const int N = 3e4+100;
using ll = __int128_t;

long long a[N];
int n;
int main() {
    cin >> n;
    ll tmp = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tmp += a[i] * a[i - 1];
        a[i] += a[i - 1];
    }
    int c[100], len = 0;
    while (tmp > 0) {
        c[++len] = tmp % 10;
        tmp /= 10;
    }
    for (int i = len; i > 0; --i) {
        cout << c[i];
    }
    return 0;
}