#include <iostream>

using namespace std;

#include <vector>
#include <cstring>
#include <algorithm>

using ll = long long;

ll dp[2][1003];
int a[1003];

void sol() {
    int n;
    cin >> n;
    int pre = 1, now = 0;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[now][0] = 0;
    for (int i = 2; i <= n; ++i) {
        swap(now, pre);
        memset(dp[now], 0x3f, sizeof(dp[now]));
        dp[now][0] = dp[pre][0] + abs(a[i] - a[i - 1]);
        dp[now][i - 1] = dp[pre][0];
        for (int j = 1; j < i; ++j) {
            // 1
            dp[now][i - 1] = min(dp[now][i - 1], dp[pre][j] + abs(a[i] - a[j]));
            dp[now][j] = min(dp[now][j], dp[pre][j] + abs(a[i] - a[i - 1]));
        }
    }
    cout << (*min_element(dp[now], dp[now] + n)) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        sol();
    }
    return 0;
}