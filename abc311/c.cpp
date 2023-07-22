#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n;
const int mxn = 200001;
vector<int> adj[mxn];
bool vis[mxn];
bool finished[mxn];
int parents[mxn];

void print_cycle(int node) {
    vector<int> ans;
    ans.push_back(node);
    int cur = parents[node];
    while(cur != node) {
        ans.push_back(cur);
        cur = parents[cur];
    }

    std::reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto c : ans) {
        cout << c << " ";
    }
    exit(0);
}

void dfs(int node) {
    vis[node] = true;
    for(int v : adj[node]) {
        if(!vis[v]) {
            parents[v] = node;
            dfs(v);
        } else if(!finished[v]) {
            parents[v] = node;
            print_cycle(node);
        }
    }
    finished[node] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(parents, 0, sizeof(parents));

    cin >> n;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        adj[i+1].push_back(v);
    }

    for(int i = 0; i < n; i++) {
        int v = i + 1;
        if(!vis[v]) {
            dfs(v);
        }
    }

    return 0;
}