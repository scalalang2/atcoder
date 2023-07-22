#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0 , 1, 0};

int ans = 0;
int n, m;
const int mxn = 202;
int sy = 2;
int sx = 2;
int table[mxn][mxn];
bool vis[mxn][mxn][4];
bool chk[mxn][mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 0; i < mxn; i++)
        for(int j = 0; j < mxn; j++)
            table[i][j] = 1;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        for(int j = 1; j <= m; j++) {
            if(x[j-1] == '#') {
                table[i][j] = 1;
            } else {
                table[i][j] = 0;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({sy, sx, 0});
    chk[sy][sx] = true;
    while(!q.empty()) {
        int y, x, dir;
        tie(y, x, dir) = q.front();
        q.pop();
        if(vis[y][x][dir]) continue;
        vis[y][x][dir] = true;
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 1 || ny > n || nx < 1 || nx > m) continue;
        if(table[ny][nx] == 1) {
            // 충돌이라면
            for(int i = 0; i < 4; i++) {
                if(i == dir) continue;
                if(vis[y][x][i]) continue;
                q.push({y, x, i});
            }
        } else {
            // 충돌이 아니라면
            chk[ny][nx] = true;
            q.push({ny, nx, dir});
        }

    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(chk[i][j]) ans++;
    cout << ans << endl;
    return 0;
}