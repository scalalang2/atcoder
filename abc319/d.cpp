#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 100000;
const ll llINF = 1e18;

int N, M;
int A[200001];

// cal 함수는 글자를 width에 끼워 맞췄을 때,
// 몇 줄이 나오는지를 반환한다.
int cal(ll width, bool debug) {
    ll w = 0;
    int lines = 1;
    for(int i = 0; i < N; i++) {
        if(A[i] > width) return INF;
        ll nw = (w > 0) ? w + 1 + A[i] : w + A[i];
        if(nw > width) {
            lines++;
            w = A[i];
        } else {
            w = nw;
        }
    }
    return lines;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> A[i];

    // 글자를 딱 M줄에 끼워 맞추려고 한다면 몇 W가 필요할까?
    // sum(A[i:j]) + (j-i-1) <= W 요게 3 세트가 나와야 한다는 거지
    // 이분 탐색
    // 계산 된 m이 m >= M 이라면? W 증가
    // m < M 작으면, W 감소
    ll l = 0, r = llINF;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(cal(mid, false) <= M) r = mid;
        else l = mid;
    }
    cout << r << "\n";

    return 0;
}