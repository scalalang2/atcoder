#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n;
vector<int> days;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    int total = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        days.push_back(x);
        total += x;
    }

    int mid = (total+1) / 2;
    int m = 1;
    int d = 0;
    for(int i = 0; i < n; i++) {
        if(days[i] < mid) {
            m++;
            mid -= days[i];
        } else {
            d = mid;
            break;
        }
    }

    cout << m << " " << d << endl;

    return 0;
}