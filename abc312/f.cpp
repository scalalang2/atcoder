#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

ll n, m;
vector<ll> A; // pull-tab can
vector<ll> B; // regular
vector<ll> C; // opener

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n ;i++) {
        ll t, x;
        cin >> t >> x;
        if(t == 0) {
            A.push_back(x);
        } else if(t == 1) {
            B.push_back(x);
        } else {
            C.push_back(x);
        }
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    // T_i = 0 / pull-tab can; X_i 만큼 해피하다.
    // T_i = 1 / regular_can 이고 캔 오프너를 사용하면 X_i만큼 해피하다.
    // T_i = 2 / 캔 오프너이고 X_i 캔 만큼 딸 수 있다.
    vector<ll> PS(n+1, 0);
    vector<ll> PS2(n+1, 0);
    for(int i = 1; i <= n; i++) {
        if(i <= A.size()) {
            PS[i] = A[i - 1];
            if (i != 0) PS[i] += PS[i - 1];
        } else {
            PS[i] = PS[i - 1];
        }
    }

    int r = 0;
    for(int i = 1; i <= n; i++) {
        if(B.empty()) PS2[i] = PS2[i-1];
        else if(r == 0) {
            if(!C.empty()) {
                r += C.back();
                C.pop_back();
            }
            PS2[i] = PS2[i-1];
        } else {
            r--;
            PS2[i] = PS2[i-1] + B.back();
            B.pop_back();
        }
    }

    ll ans = 0;
    for(int i = 0; i <= m; i++) {
        ans = max(ans, (ll)PS[i] + (ll)PS2[m - i]);
    }
    cout << ans << endl;

    return 0;
}