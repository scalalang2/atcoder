#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;
const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;
    int N = S.size();
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i] != ')') {
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + 1] %= MOD;
            }

            if (j != 0 && S[i] != '(') {
                dp[i + 1][j - 1] += dp[i][j];
                dp[i + 1][j - 1] %= MOD;
            }
        }
    }

    cout << dp[N][0] << endl;
    return 0;
}