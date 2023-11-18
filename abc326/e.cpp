#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;
ll mod = 998244353;

ll power(ll a,ll b){
    ll x=1,y=a;
    while(b>0){
        if(b&1ll){
            x=(x*y)%mod;
        }
        y=(y*y)%mod;
        b>>=1;
    }
    return x%mod;
}

ll invmod(ll n) {
    return power(n, mod-2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 아오키는 앳코더 직원임, 월급은 N개의 시퀀스로 결저된다.
    // N면의 주사위와 x=0 변수가 있음
    // 끝날때까지 아래 스텝이 진행됨
    // 1. 주사위를 굴리고 y는 주사위 면의 숫자임
    // x < y 이면 A_y 만큼 받고 x = y라고 한다.
    // 만약 x > y 면 주사위 굴리는 걸 멈춘다.
    // 최대 월급의 기댓값을 구하여라

    // 1안
    // E = 1만 먹을 값, 2만 먹을 값, 3만 먹을 값
    // E = 1->2로 먹는것, 1->2->3 으로 먹는 것
    // E = 기타 등등...

    // 2안
    // 생각의 전환 by Editorial
    // 각 시행에서 A_i원을 아오키에게 지불할 확률을 구하고, 기댓값을 구한다.
    ll n;
    cin >> n;
    ll invn = invmod(n);
    ll p = invn, res = 0;
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        res = (res + a*p);
        res %=mod;
        p += p*invn;
        p %= mod;
    }
    cout << res << endl;

    return 0;
}