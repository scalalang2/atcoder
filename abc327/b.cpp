#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    ll i = 1;
    while(true){
        ll ret = 1;
        for(ll k = 1; k <= i; k++) {
            ret *= i;
        }
        if(ret > n) {
            cout << -1;
            return 0;
        }
        if(ret == n) {
            cout << i;
            return 0;
        }
        i++;
    }
    cout << -1;
    return 0;
}