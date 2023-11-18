#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N;
ll T[200005];
ll D[200005];
priority_queue<ll, vector<ll>, greater<>> TIME;
set<ll> TIME_SET;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 1부터 N개의 라벨이 달린 제품이 있다.
    // 컨베이어 벨트에는 프린터가 있고 제품 i는 T_i 마이크로 세컨드에 입장하고 D_i 마이크로세컨드 이후에 퇴장한다.
    // 프린터는 즉시 제품을 인쇄할 수 있음
    // 하지만, 한번 인쇄하면 1초간 대기해야 한다.
    // 인쇄할 수 있는 최대 제품수는? (프린터를 위해 제품 및 타이밍을 최적으로 정할 수 있음)

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> T[i] >> D[i];
        TIME_SET.insert(T[i]);
        TIME_SET.insert(T[i] + D[i]);
    }

    for(auto t : TIME_SET) {
        TIME.push(t);
    }

    priority_queue<pll, vector<pll>, greater<>> start;
    priority_queue<ll, vector<ll>, greater<>> end;
    ll ans = 0;

    for(int i = 0; i < N; i++) {
        start.emplace(T[i], T[i] + D[i]);
    }

    while(!TIME.empty()) {
        ll t = TIME.top();
        TIME.pop();

        // 현재 시간에 해당하는 애 넣음
        while(!start.empty() && start.top().first <= t) {
            auto [s, e] = start.top();
            start.pop();
            end.emplace(e);
        }

        // 프린터 시야 밖에 있는 제품은 모두 제거
        while(!end.empty() && end.top() < t) {
            end.pop();
        }

        if(!end.empty()) {
            ll e = end.top();
            // cout << t << " " << e << endl;
            if (t <= e) {
                ans++;
                end.pop();
                if(TIME_SET.count(t + 1) == 0) TIME.push(t + 1);
            }
        }
    }

    cout << ans << endl;

    return 0;
}