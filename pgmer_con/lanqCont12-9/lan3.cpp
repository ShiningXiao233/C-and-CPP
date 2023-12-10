#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
vector<ll> a;
vector<bool> np;
vector<int> pr;

int main() {
    int n;
    cin >> n;
    
    a.resize(n + 3);
    np.resize(n + 1000);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }    
    
    for (int i = 2; i < n + 1000; ++i) {
        if (!np[i]) pr.push_back(i);
        for (int j = i + i; j < n + 1000; j += i) {
            np[j] = 1;
        }
    }
    ll ans = -1e16;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; i - pr[j] >= 0 && j < pr.size(); ++j) {
            ans = max(ans, a[i] - a[i - pr[j]]);
        }
    }
    cout << ans << endl;
    return 0;
}