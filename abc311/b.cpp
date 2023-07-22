#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, d;
vector<string> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> d;
    for(int i = 0; i < n; i++) {
        string x;
        cin >> x;
        arr.push_back(x);
    }

    int ans = 0;
    int a = 0;
    for(int i = 0; i < d; i++) {
        bool flag = true;
        bool prev = true;
        for(int j = 0; j < n; j++) {
            if(arr[j][i] == 'x') {
                flag = false;
                break;
            }
            if(j > 0) {
                if(arr[j-1][i] == 'x') {
                    prev = false;
                    break;
                }
            }
        }
        if(prev && flag) {
            a++;
            ans = max(ans, a);
        } else if(flag) {
            a = 1;
            ans = max(ans, a);
        }
        if(!flag) {
            a = 0;
        }
    }

    cout << ans << endl;

    return 0;
}