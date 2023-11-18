#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vv = pair<char, int>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n;
string r, c;
vector<vector<char>> grid;

map<char, bool> mrows[5];
map<char, bool> mcols[5];

bool check() {
    vector<set<char>> rows;
    vector<set<char>> cols;
    rows.resize(n);
    cols.resize(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && grid[i][j] != c[j]) return false;
            if(j == 0 && grid[i][j] != r[i]) return false;
            if(grid[i][j] != 0) {
                if(rows[i].count(grid[i][j]) || cols[j].count(grid[i][j])) return false;
                rows[i].insert(grid[i][j]);
                cols[j].insert(grid[i][j]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(rows[i].size() != 3 || cols[i].size() != 3) return false;
    }

    return true;
}

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

bool make_grid(int i, int j) {
    if(i >= n || j >= n) {
        return check();
    }

    for(char ch = 'A'; ch <= 'C'; ch++) {
        if(i == 0 && c[j] != ch) continue;
        if(j == 0 && r[i] != ch) continue;
        // 각 행과 컬럼에 이미 A,B,C 중 하나가 있다면
        if(mrows[i][ch] || mcols[j][ch]) continue;
        grid[i][j] = ch;
        mrows[i][ch] = true;
        mcols[j][ch] = true;
        if(make_grid(i, j+1) || make_grid(i+1, j)) {
            return true;
        }
        mrows[i][ch] = false;
        mcols[j][ch] = false;
        grid[i][j] = '.';
    }
    return make_grid(i, j+1) || make_grid(i+1, j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // N과 N의 길이를 가진 R,C 두 개의 문자열을 얻는다
    // 문자열은 A, B, C로만 이루어져 있다.
    // NxN 그리드를 만들어라
    // 각 칸에는 A,B,C 중 하나만 둘 수 있다.
    //
    // 각 row, column은 오직 하나의 A, B, C 만 가져야 한다.
    // 가장 왼쪽의 character는 R의 i번째 char와 일치해야 한다.
    // 가장 오른쪽의 char는 C의 i번째 char와 일치해야 한다.
    // 가능 하면 그러한 테이블을 출력하고
    // 불가능 하면 No를 출력해라

    // 무조건, 하늘이 두쪽나도 백트래킹 문제이다.

    cin >> n >> r >> c;
    grid.resize(n, vector<char>(n, '.'));

    if(!make_grid(0, 0)) {
        cout << "No";
    } else {
        print();
    }

    return 0;
}