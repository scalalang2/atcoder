#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

/*
 * Relative Position
 * 1 -> 2 ->
 * */

struct edge {
    int to;
    ll x;
    ll y;
};

vector<edge> adj[200005];
bool vis[200005];
ll X[200005];
ll Y[200005];
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v;
        ll x, y;
        cin >> u >> v >> x >> y;
        adj[u].push_back({v, x, y});
        adj[v].push_back({u, -x, -y});
    }

    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    while(!Q.empty()) {
        int curr = Q.front();
        Q.pop();

        for(auto nxt : adj[curr]) {
            if(vis[nxt.to]) continue;
            X[nxt.to] = X[curr] + nxt.x;
            Y[nxt.to] = Y[curr] + nxt.y;
            vis[nxt.to] = true;
            Q.push(nxt.to);
        }
    }

    for(int i = 1; i <= N; i++) {
        if(!vis[i]) {
            cout << "undecidable" << '\n';
            continue;
        }

        cout << X[i] << " " << Y[i] << '\n';
    }

    return 0;
}