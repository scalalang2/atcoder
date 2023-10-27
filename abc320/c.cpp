#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int M;
string A, B, C;

map<char, bool> vis;

int pick(char c, int t) {
    int ret = INF;
    if(t == M * 3 + 1) return ret;
    if(vis['A'] && vis['B'] && vis['C']) {
        return t;
    }

    if(!vis['A'] && A[t%M] == c) {
        vis['A'] = true;
        ret = min(ret,pick(c, t + 1));
        vis['A'] = false;
    }
    if(!vis['B'] && B[t%M] == c) {
        vis['B'] = true;
        ret = min(ret,pick(c, t + 1));
        vis['B'] = false;
    }
    if(!vis['C'] && C[t%M] == c) {
        vis['C'] = true;
        ret = min(ret, pick(c, t + 1));
        vis['C'] = false;
    }
    ret = min(ret, pick(c, t+1));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M;
    cin >> A >> B >> C;

    int ans = INF;
    for(char c = '0'; c <= '9'; c++) {
        ans = min(ans, pick(c, 0));
    }

    if(ans == INF) cout << -1;
    else cout << ans-1<< endl;

    return 0;
}