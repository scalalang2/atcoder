#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int H, W;
char world[2001][2001];
bool vis[2001][2001];
vector<int> rows[2001];
vector<int> cols[2001];
int dist[2001][2001];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

int sy, sx;
int gy, gx;

bool inrange(int y, int x) {
    return 1 <= y && y <= H && 1 <= x && x <= W;
}

// watching 누군가 보고 있다
// 행에서 가까운 걸 찾음
bool watching(int y, int x) {
    if(rows[y].size() > 0) {
        int idx = lower_bound(rows[y].begin(), rows[y].end(), x) - rows[y].begin();
        int right = idx == rows[y].size() ? -1 : rows[y][idx];
        int left = (idx == 0) ? -1 : rows[y][idx - 1];
        if(left != -1 && world[y][left] == '>') return true;
        if(right != -1 && world[y][right] == '<') return true;
    }
    if(cols[x].size() > 0) {
        int idx = lower_bound(cols[x].begin(), cols[x].end(), y) - cols[x].begin();
        int left = idx == 0 ? -1 : cols[x][idx - 1];
        int right = idx == cols[x].size() ? -1 : cols[x][idx];
        if(left != -1 && world[left][x] == 'v') return true;
        if(right != -1 && world[right][x] == '^') return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> H >> W;
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            cin >> world[i][j];
            if(world[i][j] == 'S') sy = i, sx = j;
            if(world[i][j] == 'G') gy = i, gx = j;
            if(world[i][j] == '>' || world[i][j] == '<' || world[i][j] == '^' || world[i][j] == 'v' || world[i][j] == '#') {
                rows[i].push_back(j);
                cols[j].push_back(i);
            }
        }
    }

    fill(&dist[0][0], &dist[0][0] + 2001 * 2001, INF);
    queue<pi> Q;
    Q.emplace(sy, sx);
    dist[sy][sx] = 0;

    while(!Q.empty()) {
        auto[cy,cx] = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(!inrange(ny, nx)) continue;
            if(watching(ny,nx)) continue;
            if(world[ny][nx] == '#') continue;
            if(world[ny][nx] == '>' || world[ny][nx] == '<' || world[ny][nx] == '^' || world[ny][nx] == 'v') continue;
            if(dist[ny][nx] <= dist[cy][cx] + 1) continue;
            dist[ny][nx] = dist[cy][cx] + 1;
            Q.emplace(ny, nx);
        }
    }

    if(dist[gy][gx] == INF) cout << -1;
    else cout << dist[gy][gx];


    return 0;
}