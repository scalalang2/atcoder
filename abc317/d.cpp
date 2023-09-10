#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;
const int mxn = 101;

int N;

// i는 선거구역을 의미하고
// X가 타카하시 표
// Y가 아오키 표
// Z가 해당 선거구의 득표수 인데
// 총 Z가 다수를 넘겨야 하는 상황임
ll X[mxn], Y[mxn], Z[mxn];
ll T, A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
        if(X[i] > Y[i]) T += Z[i];
        else A += Z[i];
    }

    if(T > A) {
        cout << 0;
        return 0;
    }

    vector<pi> arr;
    ll target = A - T;
    for(int i = 0; i < N; i++) {
        if(X[i] > Y[i]) continue;
        arr.emplace_back((Y[i]-X[i]+1)/2, Z[i]);
    }
    sort(arr.begin(), arr.end());

    ll ans = llINF;
    vector<vector<ll>> dp(arr.size()+1, vector<ll>(100001, llINF));
    for(int i = 0; i <= arr.size(); i++) dp[i][0] = 0;
    for(int i = 1; i <= arr.size(); i++){
        dp[i][arr[i-1].second] = arr[i-1].first;
        dp[i][arr[i-1].second] = min(dp[i][arr[i-1].second], dp[i-1][arr[i-1].second]);
        for(int j = 0; j < 100001; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(j - arr[i-1].second >= 0) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-arr[i-1].second] + arr[i-1].first);
            }
        }
    }

    for(ll i = 0; i < 100001; i++) {
        if(target-i <= i) {
            ans = min(ans, dp[arr.size()][i]);
        }
    }

    cout << ans << endl;

    return 0;
}