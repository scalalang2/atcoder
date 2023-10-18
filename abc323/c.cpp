#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, M;
vector<pi> scores;
string board[101];
vector<int> cals;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    cals.resize(N);
    scores.resize(M);
    for(int i = 0; i < M; i++) {
        int x;
        cin >> x;
        scores[i] = {x, i};
    }
    for(int i = 0; i < N; i++) cin >> board[i];
    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 'o') {
                cals[i] += scores[j].first;
            }
        }
        cals[i] += i+1;
    }

    int max_value = 0;
    for(int i = 0; i < N; i++)
        max_value = max(max_value, cals[i]);

    sort(scores.begin(), scores.end(), greater<>());

    for(int i = 0; i < N; i++) {
        if(cals[i] == max_value) {
            cout << 0 << "\n";
            continue;
        }
        int total = cals[i];
        int cnt = 0;
        for(auto [score, idx] : scores) {
            if(board[i][idx] == 'x') {
                total += score;
                cnt++;
                if(total > max_value) {
                    cout << cnt << "\n";
                    break;
                }
            }
        }
    }


    return 0;
}