#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N;
vector<pi> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int w, x;
        cin >> w >> x;
        arr.emplace_back(w, x);
    }

    int ans = 0;
    for(int k = 0; k < 24; k++) {
        int sum = 0;
        for(int i = 0; i < N; i++) {
            int t = (arr[i].second + k)%24;
            if(t >= 9 && t <= 17) {
                sum += arr[i].first;
            }
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}