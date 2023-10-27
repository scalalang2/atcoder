#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = LLONG_MAX;

ll N, A, B, C;
ll G[1001][1001];

ll dist_car[1001];
ll dist_train[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // but not vice versa.
    // 시발거 ㅋㅋ 영어 해석좀 제대로좀 하자 ^^

    cin >> N >> A >> B >> C;
    for(int i = 1; i <= N; i++) {
        dist_car[i] = llINF;
        dist_train[i] = llINF;
        for (int j = 1; j <= N; j++)
            cin >> G[i][j];
    }

    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.emplace(0, 1);
    dist_car[1] = 0;
    while(!pq.empty()) {
        auto [D, cur] = pq.top();
        pq.pop();

        for(int nxt = 1; nxt <= N; nxt++) {
            if(nxt == cur) continue;
            ll car = D + G[cur][nxt] * A;
            if(dist_car[nxt] > car) {
                dist_car[nxt] = car;
                pq.emplace(dist_car[nxt], nxt);
            }
        }
    }

    pq.emplace(0, N);
    dist_train[N] = 0;
    while(!pq.empty()) {
        auto [D, cur] = pq.top();
        pq.pop();

        for(int nxt = 1; nxt <= N; nxt++) {
            if(nxt == cur) continue;
            ll train = D + G[cur][nxt] * B + C;
            if(dist_train[nxt] > train) {
                dist_train[nxt] = train;
                pq.emplace(dist_train[nxt], nxt);
            }
        }
    }

    ll ans = llINF;
    for(int i = 1; i <= N; i++)
        ans = min(ans, dist_car[i] + dist_train[i]);

    cout << ans << endl;

    return 0;
}