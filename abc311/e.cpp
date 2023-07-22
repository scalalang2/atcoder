#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int table[2001][2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, w, n;
    cin >> h >> w >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        table[a][b] = 1;
    }



    return 0;
}