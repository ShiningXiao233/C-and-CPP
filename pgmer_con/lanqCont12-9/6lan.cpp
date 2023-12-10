#include <iostream>

using namespace std;
const int MOD = 998244353;

int qp(int x, int p = MOD - 2) {
    int res = 1;
    while (p) {
        if (p & 1) res = 1ll * res * x % MOD;
        p >>= 1;
        x = 1ll * x * x % MOD;
    }
    return res;
}
const int N = 1e5+100;
int p[N], dp[N], g[N];
int n, m;

int main() {
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum += p[i];
    }    
    for (int i = n; i > 0; --i) {
        g[i] = p[i];
        g[i] += g[i + 1];
    }
    for (int i = m - 1; i >= 1; --i) {
        int tmp = 1ll * p[1]% MOD;
        int cnt = 1;
        for (int j = 2; 1ll * j * i < m && j <= n; ++j) {
            tmp += 1ll * (dp[j * i] + 1) * p[j] % MOD;
            tmp %= MOD;
            cnt = j;
        }
        tmp += 1ll * g[cnt + 1];
        tmp = 1ll * tmp % MOD;
        dp[i] = 1ll * tmp * qp(sum - p[1]) % MOD;
    }
    cout << dp[1] << endl;
    return 0;
}