#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int arr[102][102][102];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        // 애초에 서로 겹친다는 보장이 없으니 이렇게 for문 4개 돌려도 됨
        for(int x = x1; x < x2; x++) {
            for(int y = y1; y < y2; y++) {
                for(int z = z1; z < z2; z++) {
                    arr[x+1][y+1][z+1] = i+1;
                }
            }
        }
    }

    vector<set<int>> ans(n+1);
    for(int x = 1; x <= 100; x++) {
        for(int y = 1; y <= 100; y++) {
            for(int z = 1; z <= 100; z++) {
                if(arr[x][y][z] != 0) {
                    if(arr[x+1][y][z] != 0 && arr[x][y][z] != arr[x+1][y][z]) {
                        ans[arr[x][y][z]].insert(arr[x+1][y][z]);
                        ans[arr[x+1][y][z]].insert(arr[x][y][z]);
                    }
                    if(arr[x][y+1][z] != 0 && arr[x][y][z] != arr[x][y+1][z]) {
                        ans[arr[x][y][z]].insert(arr[x][y+1][z]);
                        ans[arr[x][y+1][z]].insert(arr[x][y][z]);
                    }
                    if(arr[x][y][z+1] != 0  && arr[x][y][z] != arr[x][y][z+1]) {
                        ans[arr[x][y][z]].insert(arr[x][y][z+1]);
                        ans[arr[x][y][z+1]].insert(arr[x][y][z]);
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i].size() << "\n";
    }

    return 0;
}