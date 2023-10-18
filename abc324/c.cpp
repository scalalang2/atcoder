#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N;
string T, tmp;

bool same(string s1, string s2) {
    if(s1.size() != s2.size()) return false;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i]) return false;
    }
    return true;
}

bool isEditDistanceOne(string s1, string s2)
{
    // Find lengths of given strings
    int m = s1.length(), n = s2.length();

    // If difference between lengths is more than
    // 1, then strings can't be at one distance
    if (abs(m - n) > 1)
        return false;

    int count = 0; // Count of edits

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        // If current characters don't match
        if (s1[i] != s2[j])
        {
            if (count == 1)
                return false;

            // If length of one string is
            // more, then only possible edit
            // is to remove a character
            if (m > n)
                i++;
            else if (m< n)
                j++;
            else //Iflengths of both strings is same
            {
                i++;
                j++;
            }

            // Increment count of edits
            count++;
        }

        else // If current characters match
        {
            i++;
            j++;
        }
    }

    // If last character is extra in any string
    if (i < m || j < n)
        count++;

    return count == 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin >> T;
    vector<int> ans;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        if(same(T, tmp)) {
            ans.emplace_back(i+1);
            continue;
        }
        if(isEditDistanceOne(T, tmp)) {
            ans.emplace_back(i+1);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}