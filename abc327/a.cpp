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

    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i < s.length(); i++) {
        if(s[i-1] == 'a' && s[i] == 'b') {
            cout << "Yes";
            return 0;
        }
        if(s[i-1] == 'b' && s[i] == 'a') {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    return 0;

    return 0;
}