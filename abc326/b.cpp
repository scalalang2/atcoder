#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

bool ok(string s) {
    return (s[0] - '0') * (s[1] - '0') == (s[2] - '0');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    while(true) {
        if(ok(s)) {
            cout << s;
            return 0;
        }

        int n = stoi(s);
        n++;
        s = to_string(n);
    }

    return 0;
}