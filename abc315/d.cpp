#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int H, W;
vector<string> table;
set<int> HS, WS;
set<char> rows[2001];
set<char> cols[2001];
map<char, int> RM[2001];
map<char, int> CM[2001];

void report() {
    cout << "H -------" << endl;
    for(auto it = HS.begin(); it != HS.end(); it++) {
        cout << *it << " " << rows[*it].size() << endl;
    }

    cout << "W -------" << endl;
    for(auto it = WS.begin(); it != WS.end(); it++) {
        cout << *it << " " << cols[*it].size() << endl;
    }
}

bool clean() {
    //report();
    // h를 먼저 제거하자
    bool removed = false;
    vector<int> to_remove;
    for(set<int>::iterator h = HS.begin(); h != HS.end(); h++) {
        // 제거의 조건
        // h의 색상이 유일하게 하나이며, 원소가 2개 이상일 때
        char color = *rows[*h].begin();
        if(rows[*h].size() == 1 && RM[*h][color] >= 2) {
            // h를 제거하자
            // for(int i = 0; i < W; i++) {
            //     CM[i][color]--;
            //     if(CM[i][color] == 0) cols[i].erase(color);
            // }
            to_remove.push_back(*h);
            removed = true;
        }
    }

    vector<int> remove_w;
    // w를 제거하자
    for(set<int>::iterator h = WS.begin(); h != WS.end(); h++) {
        // 제거의 조건
        // h의 색상이 유일하게 하나이며, 원소가 2개 이상일 때
        char color = *cols[*h].begin();
        if(cols[*h].size() == 1 && CM[*h][color] >= 2) {
            remove_w.push_back(*h);
            removed = true;
        }
    }

    for(int i = 0; i < to_remove.size(); i++) {
        int height = to_remove[i];
        char color = *cols[height].begin();
        HS.erase(height);
        for(int j = 0; j < W; j++) {
            CM[j][color]--;
            if(CM[j][color] == 0) cols[j].erase(color);
        }
    }
    for(int i = 0; i < remove_w.size(); i++) {
        int width = remove_w[i];
        char color = *cols[width].begin();
        WS.erase(width);
        for(int j = 0; j < W; j++) {
            RM[j][color]--;
            if(RM[j][color] == 0) rows[j].erase(color);
        }
    }
    return removed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> H >> W;
    for(int i = 0; i < H; i++) HS.insert(i);
    for(int i = 0; i < W; i++) WS.insert(i);

    table.resize(H);
    for(int i = 0; i < H; i++) {
        cin >> table[i];
        for(int j = 0; j < W; j++) {
            rows[i].insert(table[i][j]);
            cols[j].insert(table[i][j]);
            RM[i][table[i][j]]++;
            CM[j][table[i][j]]++;
        }
    }

    while(clean());


    //report();

    int ans = 0;
    for(set<int>::iterator it = HS.begin(); it != HS.end(); it++) {
        ans += rows[*it].size();
    }

    cout << ans << endl;

    return 0;
}