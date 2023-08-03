#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, m;
vector<int> seller;
vector<int> buyer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    seller.resize(n, 0);
    buyer.resize(m, 0);
    for(int i = 0; i < n; i++) cin >> seller[i];
    for(int i = 0; i < m; i++) cin >> buyer[i];
    vector<int> cands;
    for(int i = 0; i < n; i++) {
        cands.push_back(seller[i]);
    }
    for(int i = 0; i < m; i++) {
        cands.push_back(buyer[i] + 1);
    }

    int ans = 1e9 + 1;
    sort(seller.begin(), seller.end());
    sort(buyer.begin(), buyer.end());
    sort(cands.begin(), cands.end());
    for(auto x : cands) {
        auto l = upper_bound(seller.begin(), seller.end(), x);
        auto r = lower_bound(buyer.begin(), buyer.end(), x);
        int p = 0;
        if(l == seller.end()) p = n;
        else if(l - seller.begin() == 0) p = 0;
        else p = l - seller.begin();
        int q = 0;
        if(r == buyer.end()) q = 0;
        else if(r - buyer.begin() == 0) q = m;
        else q = m - (r - buyer.begin());

        if(p >= q) {
            cout << x << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 0;
}