#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;

#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i >= a; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
public:
   // Solution() {
      
   // }

    pair<bool, pair<int, int>> solve() {
        int n; string s;
        cin >> n >> s;
        pair<bool, pair<int, int>> ans(false, {-1, -1});
        int i = 0, j = 1;
        while(i < n && j < n) {
            if(s[j] < s[i]) {
                ans.first = true;
                ans.second.first = i+1;
                ans.second.second = j+1;
                return ans;
            }
            i++; j++;
        }
        return ans;
    }
};

signed main() {
    fastio

    Solution sol;
    pair<bool, pair<int, int>> ans = sol.solve();
    if(ans.first) {
        cout << "YES\n";
        cout << ans.second.first << " " << ans.second.second << "\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}