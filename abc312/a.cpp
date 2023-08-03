#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

string arr[7] = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string x;
    cin >> x;
    for(int i = 0; i < 7; i++) {
        if(arr[i] == x) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";

    return 0;
}