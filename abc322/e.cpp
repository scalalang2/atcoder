#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, K, P;
ll cost[101];
int values[101][6];

const int MP = 5;
const int max_state = 1 << 26;
map<map<int, int>, ll> dp[101];
vector<map<int, int>> all_state;
map<int, int> g;

/*
 * K개의 파라미터가 있고 P점수가 있죠
 * K개의 파라미터가 전부 P점수까지 채워져야 하는 상황이고
 *
 * K <= P <= 5
 * P**K
 * 이런 상태들을 전부 만들어두고 배낭문제처럼 풀어보자
 *
 * dp[i][state] = min(dp[i][state], dp[i-1][state] + cost[i])
 * */

void generate(int k) {
    if(k == K+1) {
        all_state.push_back(g);
        return;
    }

    for (int i = 0; i <= P; i++) {
        g[k] = i;
        generate(k + 1);
    }
}

map<int, int> add(map<int, int> v, int idx) {
    map<int, int> ret;
    for(int i = 1; i <= K; i++) {
        ret[i] = v[i] + values[idx][i];
        if(ret[i] >= P) ret[i] = P;
    }
    return ret;
}

// 이거 그냥 조금 손 많이 타는 배낭 문제 급 아님..?
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K >> P;
    for(int i = 1; i <= N; i++) {
        cin >> cost[i];
        for(int j = 1; j <= K; j++) cin >> values[i][j];
    }

    generate(1);

    for(int i = 0; i <= N; i++) {
        for(auto el : all_state) {
            dp[i][el] = llINF;
        }
    }

    map<int, int> init;
    for(int i = 1; i <= K; i++) init[i] = 0;
    dp[0][init] = 0;

    for(int i = 1; i <= N; i++) {
        for(auto el : all_state) {
            // 배낭에 넣는다면
            dp[i][add(el, i)] = min(dp[i][add(el, i)], dp[i-1][el] + cost[i]);

            // 배낭에 안넣는다면
            dp[i][el] = min(dp[i][el], dp[i-1][el]);
        }
    }

    // 타겟값은? 각 최댓값을 도는 것
    ll ans = llINF;
    map<int, int> t;
    for(int i = 1; i <= K; i++) t[i] = P;
    for(int i = 1; i <= N; i++) {
        ans = min(ans, dp[i][t]);
    }

    if(ans == llINF) cout << -1;
    else cout << ans;

    return 0;
}