#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, x;
int bet_count[101];
map<pi, bool> bets;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        bet_count[i] = c;
        for(int j = 0; j < c; j++) {
            int a;
            cin >> a;
            bets[{i, a}] = true;
        }
    }

    cin >> x;
    int m = INF;
    vector<int> people;
    for(int i = 1; i <= n; i++) {
        if(bets[{i, x}]) {
            people.push_back(i);
            m = min(m, bet_count[i]);
        }
    }

    vector<int> ans;
    for(auto &p : people) {
        if(bet_count[p] == m) {
            ans.push_back(p);
        }
    }

    cout << ans.size() << endl;
    for(auto &p : ans) {
        cout << p << " ";
    }

    return 0;
}