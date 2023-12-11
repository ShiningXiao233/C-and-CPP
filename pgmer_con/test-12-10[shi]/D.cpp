#include <iostream>

using namespace std;
int n, m;
const int N = static_cast<int>(1e5+10);
int num[N];
#include <cstring>

void sol() {
    cin >> n >> m;
    memset(num, 0, sizeof(int) * n);
    int a, b;
    for (int i = 1; i <= m; ++i) {
        cin >> b >> a;
        b -= a;
        b %= n;
        num[(n - b) % n] ++;
    }
    using ll = long long;
    ll tmp = 0, ans = 1e18;
    for (int i = 0; i < n; ++i) tmp += 1ll * i * num[i];
    ans = tmp;
    for (int i = 1; i < n; ++i) {
        tmp += (m - num[n - i]);
        tmp -= 1ll * (n - 1) * num[n - i];
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        sol();
    }
    return 0;
}