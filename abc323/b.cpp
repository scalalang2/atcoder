#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N;
string arr[101];
vector<pi> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            if(arr[i][j] == 'o') {
                cnt++;
            }
        }
        ans.emplace_back(-cnt, i+1);
    }

    sort(ans.begin(), ans.end());
    for(int i = 0; i < N; i++) {
        cout << ans[i].second << " ";
    }

    return 0;
}