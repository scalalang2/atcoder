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

    int x,y;
    cin >> x >> y;
    if(y > x && y - x <= 2) cout << "Yes";
    else if(x > y && x - y <= 3) cout << "Yes";
    else if(x == y) cout << "Yes";
    else cout << "No";

    return 0;
}