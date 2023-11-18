#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int H, W;
int table[1001][1001];
bool vis[1001][1001];
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

void mark(int i, int j) {
    for(int k = 0; k < 8; k++) {
        int nx = j + dx[k];
        int ny = i + dy[k];
        if(nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
        if(vis[ny][nx]) continue;
        if(table[ny][nx] == 0) continue;
        vis[ny][nx] = true;
        mark(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> H >> W;
    for(int i = 0; i < H; i++) {
         cin >> s;
         for(int j = 0; j < W; j++) {
             if(s[j] == '#') table[i][j] = 1;
             else table[i][j] = 0;
         }
    }

    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(table[i][j] == 0) continue;
            if(vis[i][j]) continue;
            vis[i][j] = true;
            mark(i, j);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}