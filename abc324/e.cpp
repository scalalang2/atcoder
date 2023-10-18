#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N;
string T;
string S[500005];
int cnt[500005];
int p[500005];

int prefix(string *a, string *b) {
    int ret = 0;

    int i = 0;
    int j = 0;
    while(i < a->size() && j < b->size()) {
        if((*a)[i] == (*b)[j]){
            ret++, i++, j++;
        } else {
            i++;
        }
    }
    return ret;
}

int suffix(string *a, string *b) {
    int ret = 0;

    int i = a->length() - 1;
    int j = b->length() - 1;
    while(i >= 0 && j >= 0) {
        if((*a)[i] == (*b)[j]){
            ret++,i--,j--;
        } else {
            i--;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> T;
    int sz = T.size();
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        S[i] = s;
        int suffixed = suffix(&s, &T);
        cnt[suffixed]++;
    }

    for(int i = sz; i >= 0; i--) {
        cnt[i] += cnt[i+1];
    }

    ll ans = 0;
    for(int i = 0; i < N; i++) {
        int prefixed = prefix(&S[i], &T);
        if(prefixed == sz) {
            ans += N;
            continue;
        }

        ans += cnt[sz - prefixed];
    }

    cout << ans << endl;
    return 0;
}