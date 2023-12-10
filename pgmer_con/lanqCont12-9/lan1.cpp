#include <iostream>

using namespace std;

const int N = 1e5+10;
int a[N];
int n;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int t = min(0, m);
        cout << t;
        m -= t;
    }
}