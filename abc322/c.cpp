#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, M;
queue<int> Q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x;
        cin >> x;
        Q.push(x);
    }

    for(int i = 0; i < N; i++) {
        int d = i + 1;
        int firework = Q.front();
        if(firework == d) {
            Q.pop();
            cout << 0 << endl;
        } else {
            cout << firework - d << endl;
        }
    }

    return 0;
}