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

    string solve() {
        int n, r, b; cin >> n >> r >> b;
        string ans;
        int regions = b + 1;
        int extra = r % regions;
        int rLen = floor((double)r/regions);
        loop(i, 1, b+2) {
            loop(j, 0, rLen) {
                ans += "R";
            }
            if(extra > 0) {
                ans += "R";
                extra--;
            }
            if(i != b+1) {
                ans += "B";
            }
        }
        return ans;
    }

};

signed main() {
    fastio

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        cout << sol.solve() << "\n";
    }
    return 0;
}