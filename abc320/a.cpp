#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

ll A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> A >> B;
    ll AA = 1;
    ll BB = 1;
    for(int i = 0; i < A; i++) BB *= B;
    for(int i = 0; i < B; i++) AA *= A;

    cout << AA + BB;

    return 0;
}