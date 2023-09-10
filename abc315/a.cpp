#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

char arr[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string x;
    cin >> x;
    string ans = "";
    for(auto c : x) {
        if(!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
            ans += c;
        }
    }

    cout << ans << endl;



    return 0;
}