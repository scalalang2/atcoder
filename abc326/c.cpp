#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, M;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // N개의 선물이 있다.
    // i번째 선물은 좌표 A_i 에 있다.
    // [x, x+M) 의 라인을 골라서 모든 선물을 골라 넣는다.
    // - 자연수 x를 선택함
    // - x <= A_i < x + M 사이의 선물을 모두 고름
    // 질문 : 선물의 최대 갯수를 구하여라

    // 정렬 이후 바이너리 서치로 모두 구하기

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int x = arr[i] + M;
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        ans = max(ans, idx - i);
    }

    cout << ans;

    return 0;
}