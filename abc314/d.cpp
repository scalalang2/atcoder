#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, q;
string S;
int t,x;
char c;

int upper, lower;

vector<int> changelog;
vector<char> uc;
vector<char> lc;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cin >> S;
    cin >> q;

    changelog.resize(n, 0);

    for(int i = 0; i < 26; i++) {
        uc.push_back('A' + i);
        lc.push_back('a' + i);
    }

    upper = -1;
    lower = -1;

    // 풀이의 핵심은
    // t=1 일때 S[x] = c 로 변경하는 경우,
    // 내가 들어오고 나서, 이후에 변경에 대한 명령이 존재했는가? => 그렇다면 바꿔서 출력, 아니라면 그대로 출력
    int i = 0;
    while(q--) {
        cin >> t >> x >> c;
        if(t == 1) {
            S[x-1] = c;
            changelog[x-1] = i;
        } else if(t == 2) {
            lower = i;
        } else {
            upper = i;
        }

        i++;
    }

    // 코드를 더 깔끔하게 만들 수는 없었는지 한 번 더 체크해보자
    for(int i = 0; i < n; i++) {
        // 이거 upper_case 판별을 더 잘할 수 있는 방법 없나.
        bool upper_case;
        if(S[i] - 'a' >= 0) upper_case = false;
        else upper_case = true;

        // i번 문자열의 변경이 가장 컸던 거라면?
        // 그냥 그대로 간다.
        if(changelog[i] > upper && changelog[i] > lower) {
            cout << S[i];
        } else {
            if(upper > lower) {
                if(upper_case) cout << S[i];
                else cout << uc[S[i] - 'a'];
            } else {
                if(upper_case) cout << lc[S[i] - 'A'];
                else cout << S[i];
            }
        }
    }

    return 0;
}