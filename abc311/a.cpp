#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

bool check[3];
int n;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cin >> s;

    for(int i = 0; i < n; i++) {
        check[s[i] - 'A'] = true;
        bool flag = true;
        for(bool l : check) {
            if(!l) flag = false;
        }
        if(flag) {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}