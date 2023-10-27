#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N;
ll D[100005];
ll dp[100005][1001][1001];
ll L1, C1, K1;
ll L2, C2, K2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 컨베이어 벨트의 다양한 구역을 감시한다.
    // N개의 섹션이 존재하고 i번째 섹션은 D_i 미터를 가지고 있다.

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> D[i];
    }
    cin >> L1 >> C1 >> K1;
    cin >> L2 >> C2 >> K2;

    for(int i = 0; i <= 100000; i++) {
        for(int j = 1; j <= 1000; j++) {
            for(int k = 1; k <= 1000; k++) {
                dp[i][j][k] = llINF;
            }
        }
    }

    dp[0][0][0] = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= 1000; j++) {
            for(int k = 0; k <= 1000; k++) {
                // 개수 초과 안됨
                if(j > K1) continue;
                if(k > K2) continue;
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k])
            }
        }
    }

    return 0;
}