#include <iostream>

using namespace std;
const int N = (1 << 20) + 10;

int num[N], x[N];
int a[N];
int n;

int main() {
    cin >> n;
    int cnt0 = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            cnt0 ++;
            continue;
        }
        num[a[i]] ++;
        x[a[i]] ++;
    }    
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < (1 << 20); ++j) {
            if (j >> i & 1) {
                num[j] += num[j ^ (1 << i)];
            }
        }
    }
    int ST = (1 << 20) - 1;
    long long ans = 0;
    for (int i = 0; i < (1 << 20); ++i) {
        if (x[i]) {
            ans += 1ll * x[i] * num[ST ^ i];
            // cout << x[i] << ' ' << num[ST ^ i] << endl; 
        }   
    }
    ans += 1ll * cnt0 * cnt0;
    ans += 2ll * cnt0 * (n - cnt0);
    cout << ans << endl;
    return 0;
}