#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, M;
vector<int> adj[11];
int cost[11][11];
bool visited[11];
int ans = 0;

void dfs(int curr, int dist) {
    for(int next : adj[curr]) {
        if(visited[next]) continue;
        visited[next] = true;
        dfs(next, dist + cost[curr][next]);
        visited[next] = false;
    }
    ans = max(ans, dist);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u][v] = max(cost[u][v], c);
        cost[v][u] = max(cost[u][v], c);
    }

    for(int i = 1; i <= N; i++) {
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;
    }

    cout << ans << endl;

    return 0;
}