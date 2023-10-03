#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, M;
string S, T;

bool prefix() {
    for(int i = 0; i < N; i++) {
        if(S[i] != T[i]) return false;
    }
    return true;
}

bool suffix() {
    for(int i = 0; i < N; i++) {
        if(S[i] != T[M - N + i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    cin >> S >> T;

    if(prefix() && suffix()) {
        cout << 0;
    } else if(prefix()) {
        cout << 1;
    } else if(suffix()) {
        cout << 2;
    } else {
        cout << 3;
    }

    return 0;
}