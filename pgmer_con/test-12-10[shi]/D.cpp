#include <iostream>

using namespace std;
int n, m;
const int N = static_cast<int>(1e6+10);
int num[N];
#include <cstring>

void sol() {
    cin >> n >> m;
    if (n >= 10000000) {
        while (1);
    }
    for (int i = 1; i <= n; ++i) num[i] = 0;
    return;
    int a, b;
    for (int i = 1; i <= m; ++i) {
        cin >> b >> a;
        b -= a;
        b %= n;
        b = (b + n) % n;
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
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t --) {
        sol();
    }
    return 0;
}