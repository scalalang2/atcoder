#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

map<string, int> M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    M["tourist"] = 3858;
    M["ksun48"] = 3679;
    M["Benq"] = 3658;
    M["Um_nik"] = 3648;
    M["apiad"] = 3638;
    M["Stonefeang"] = 3630;
    M["ecnerwala"] = 3613;
    M["mnbvmar"] = 3555;
    M["newbiedmy"] = 3516;
    M["semiexp"] = 3481;

    string x;
    cin >> x;
    cout << M[x] << endl;

    return 0;
}