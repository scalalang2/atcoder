#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

string target[9] = {
    "###.?????",
    "###.?????",
    "###.?????",
    "....?????",
    "?????????",
    "?????....",
    "?????.###",
    "?????.###",
    "?????.###",
};
string table[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pi> ans;
    for(int i = 0; i < n; i++) cin >> table[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i+9 > n or j+9 > m) continue;
            bool flag = true;
            for(int k = 0; k < 9; k++) {
                for(int l = 0; l < 9; l++) {
                    if(target[k][l] == '?') continue;
                    if(table[i+k][j+l] != target[k][l]) flag = false;
                }
            }
            if(flag) {
                int k = i+1;
                int l = j+1;
                ans.push_back({k, l});
            }
        }
    }

    sort(ans.begin(), ans.end());
    for(auto c : ans) {
        cout << c.first << " " << c.second << '\n';
    }

    return 0;
}