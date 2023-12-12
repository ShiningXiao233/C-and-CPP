#include <iostream>

using namespace std;

int n, m, e, s;
const int N = static_cast<int>(1e5+10);

#include <vector>

using Pair = pair<int, int>;

vector<Pair> G[N];
int dis[N];

#include <queue>
#include <cstring>

bool getg(int x) {
    queue<int> q;
    memset(dis, -1, sizeof(dis));
    q.push(s);
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == e) return 1;
        for (auto [v, t] : G[u]) {
            if (dis[v] == -1 && dis[u] + 1 <= t - x) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return 0;
}

void sol() {
    cin >> n >> m >> s >> e;
    int a, b, t;
    for (int i = 1; i <= n; ++i) G[i].clear();

    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> t;
        G[a].push_back(make_pair(b, t));
        G[b].push_back(make_pair(a, t));
    }
    int ans = -1, l = 0, r = 1e9+1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (getg(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid;
        }
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