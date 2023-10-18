#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

ll N;
unordered_map<ll, ll> M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // min heap
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    cin >> N;
    for(int i = 1; i <= N; i++) {
        ll c, s;
        cin >> s >> c;
        M[s] = c;
        pq.push(s);
    }

    // 3 101
    /*
     * 3 1
     * 6 0
     * 12 1
     * 24 12
     * 48 6
     * 96 3
     * 192 1
     * */

    while(!pq.empty()) {
        ll s = pq.top();
        ll mid = M[s] / 2;
        M[s*2] += mid;
        M[s] = M[s] - (mid*2);
        pq.pop();
        if(M[s*2] > 0) pq.push(s*2);
    }

    ll ans = 0;
    for(auto it = M.begin(); it != M.end(); it++) {
        ans += it->second;
    }
    cout << ans << endl;


    return 0;
}