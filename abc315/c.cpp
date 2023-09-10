#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;
const int mxn = 300005;

int n;
vector<vector<int>> score;

// F는 서로 달라야 하고
// S는..?
// F중에서 최댓값 2개
// S중에서 최댓값들 뽑아서 한다
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    score.resize(n+1);
    for(int i = 0; i < n; i++) {
        int f, s;
        cin >> f >> s;
        score[f].push_back(s);
    }
    vector<int> candidates;
    for(int i = 1; i <= n; i++) {
        if(score[i].empty()) continue;
        sort(score[i].begin(), score[i].end(), greater<>());
        candidates.push_back(score[i][0]);
    }
    sort(candidates.begin(), candidates.end(), greater<>());
    int ans = 0;
    if(candidates.size() >= 2) {
        ans = candidates[0] + candidates[1];
    }
    for(int i = 1; i <= n; i++) {
        if(score[i].size() >= 2) {
            int tmp = score[i][0] + (score[i][1]/2);
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;

    return 0;
}