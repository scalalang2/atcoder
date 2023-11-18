#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int A[10][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 1; i <= 9; i++) {
        map<int, bool> row;
        map<int, bool> col;
        for(int j = 1; j <= 9; j++) {
            if(row[A[i][j]] || col[A[j][i]]) {
                cout << "No";
                return 0;
            }
            row[A[i][j]] = true;
            col[A[j][i]] = true;
        }
    }

    for(int i = 1; i <= 9; i += 3) {
        for(int j = 1; j <= 9; j += 3) {
            map<int, bool> m;
            for(int k = i; k <= i + 2; k++) {
                for(int l = j; l <= j + 2; l++) {
                    if(m[A[k][l]]) {
                        cout << "No";
                        return 0;
                    }
                    m[A[k][l]] = true;
                }
            }
        }
    }

    cout << "Yes";

    return 0;
}