#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

ll N, M;
ll T, W, S;
ll cnt[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    priority_queue<ll, vector<ll>, greater<ll>> rows;
    for(ll i = 1; i <= N; i++) rows.emplace(i);

    while(M--) {
        cin >> T >> W >> S;
        while(!pq.empty() && pq.top().first <= T) {
            rows.emplace(pq.top().second);
            pq.pop();
        }

        if(!rows.empty()) {
            auto curr = rows.top();
            rows.pop();
            cnt[curr] += W;
            pq.emplace(T + S, curr);
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << cnt[i] << "\n";
    }

    return 0;
}