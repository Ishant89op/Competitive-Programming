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

    ll solve() {
        ll n, m;
        cin >> n >> m;
        vector<vll> grid(n, vll(m));
        ll posGridSum = 0;
        ll negs = 0, minNeg = LONG_LONG_MAX;
        loop(i, 0, n) {
            loop(j, 0, m) {
                cin >> grid[i][j];
                if(grid[i][j] < 0) negs++;
                minNeg = min(minNeg, abs(grid[i][j]));
                posGridSum += abs(grid[i][j]);
            }
        }
        if(negs&1LL) {
            return posGridSum - 2*minNeg;
        } else {
            return posGridSum;
        }
        return 88;
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