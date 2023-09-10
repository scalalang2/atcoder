#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, c;
vector<vector<int>> G;
vector<vector<int>> adj;
vector<int> connected;
int indeg[200005];
bool vis[200005];
map<int, bool> chk;

void dfs(int curr) {
    vis[curr] = true;
    connected.push_back(curr);
    for(auto &i : G[curr]) {
        if(!vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    adj.resize(n+1);
    G.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> c;
        for(int j = 1; j <= c; j++) {
            int x;
            cin >> x;
            G[i].push_back(x);
        }
    }

    dfs(1);
    for(auto c : connected) {
        chk[c] = true;
        for(auto nxt : G[c]) {
            adj[nxt].push_back(c);
            adj[c].push_back(nxt);
            indeg[c]++;
        }
    }

    vector<int> ans;
    queue<int> Q;
    for(auto c : connected) {
        if(indeg[c] == 0) {
            Q.push(c);
            ans.push_back(c);
        }
    }
    memset(vis, false, sizeof(vis));
    while(!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        for(auto &i : adj[curr]) {
            if(!chk[i]) continue;
            if(indeg[i] < 0) continue;
            indeg[i]--;
            if(indeg[i] == 0) {
                if(i != 1) Q.push(i);
                ans.push_back(i);
            }
        }
    }

    for(auto c : ans) {
        if(c == 1) break;
        cout << c << " ";
    }

    return 0;
}