#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N;

char find(int n) {
    if(n == 0) return '1';
    for(int i = 1; i <= 9; i++) {
        if(N%i != 0) continue;
        if(N/i <= n && n%(N/i) == 0) return '0' + i;
    }
    return '-';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N+1; i++) {
        cout << find(i);
    }

    return 0;
}