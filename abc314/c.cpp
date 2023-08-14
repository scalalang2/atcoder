#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, m;
string S;
// 색상에 따른 S의 인덱스 위치
vector<vector<int>> colors;
vector<char> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    colors.resize(m+1);
    cin >> S;
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        colors[c].push_back(i);
    }

    for(auto c : S) {
        ans.push_back(c);
    }

    for(int i = 1; i <= m; i++) {
        if(colors[i].empty()) continue;

        // last digit
        char c = ans[colors[i][colors[i].size()-1]];
        for(int j = colors[i].size()-1; j > 0; j--) {
            ans[colors[i][j]] = ans[colors[i][j-1]];
        }
        ans[colors[i][0]] = c;
    }

    for(auto c : ans) {
        cout << c;
    }



    return 0;
}