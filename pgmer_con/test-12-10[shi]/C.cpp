#include <iostream>

using namespace std;
const int N = 1e5+100;

int f[N], n, x;
int num[N];

#define in(x) ((x) > 0 && (x) <= n)

bool chk(int x) {
    for (int i = 1; i <= n; ++i) num[i] = 0;
    int l = x, r = x;
    num[f[x]] = 1;
    while (1) {
        if (l == 1) {return 1;}
        if (r == n) return 1;
        if (num[l]) {
            --l;
            num[f[l]] = 1;
        } else if (num[r]) {
            ++r;
            num[f[r]] = 1;
        } else {
            break;
        }
    }
    return 0;
}

void sol() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
    }
    cout << (chk(x) ? "YES" : "NO") << endl;
}

int main() {
    int T;
    cin >> T;
    while (T --) {
        sol();
    }
    return 0;
}