#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, M;
int A[200005];
int B[200005];
vector<int> adj[200005];
bool visited[200005];
int color[200005];

void check(int node) {
    for(auto nxt : adj[node]) {
        if(visited[nxt]) {
            if(color[nxt] == color[node]) {
                cout << "No";
                exit(0);
            }
        } else {
            visited[nxt] = true;
            color[nxt] = color[node] ^ 1;
            check(nxt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < M; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    for(int i = 0; i < M; i++) {
        adj[A[i]].push_back(B[i]);
        adj[B[i]].push_back(A[i]);
    }

    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            color[i] = 0;
            check(i);
        }
    }

    cout << "Yes";

    return 0;
}
