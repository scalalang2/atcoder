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

    string S;
    cin >> S;
    for(int i = 1; i <= S.size(); i++) {
        if(i % 2 == 0 && S[i-1] != '0') {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes";
    return 0;
}