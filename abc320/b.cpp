#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

string S;

bool is_palindrome(int i, int j) {
    while(i < j) {
        if(S[i] != S[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> S;
    int ans = 1;
    for(int i = 0; i < S.size(); i++) {
        for(int j = S.size()-1; j >= i; j--) {
            if(is_palindrome(i, j)) {
                ans = max(ans, j-i+1);
            }
        }
    }

    cout << ans;

    return 0;
}