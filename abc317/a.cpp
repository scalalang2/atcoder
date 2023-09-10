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

    int n, h, x;
    cin >> n >> h >> x;
    vector<int> potions(n);
    for(int i = 0; i < n; i++) cin >> potions[i];
    for(int i = 0; i < n; i++) {
        if(potions[i] + h >= x) {
            cout << i + 1;
            return 0;
        }
    }

    return 0;
}