#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

string X = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    cout << "3.";
    for(int i = 0; i < n; i++) {
        cout << X[i];
    }

    return 0;
}