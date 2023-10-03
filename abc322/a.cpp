#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N;
string S;
char ch[3] = {'A', 'B', 'C'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin >> S;

    for(int idx = 0; idx < N; idx++) {
        bool flag = true;
        for(int i = 0; i < 3; i++) {
            if(idx + i >= N) {
                flag = false;
                break;
            }
            if(S[idx+i] != ch[i]) {
                flag = false;
            }
        }
        if(flag) {
            cout << idx + 1;
            return 0;
        }
    }

    cout << -1;

    return 0;
}