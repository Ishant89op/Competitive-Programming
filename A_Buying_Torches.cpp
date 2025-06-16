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
    ll ceilDivision(ll a, ll b) {
        return (a+b-1)/b;
    }

public:
   // Solution() {
      
   // }

    ll solve() {
        ll x, y, k;
        cin >> x >> y >> k;
        ll ans = k;
        ll totalSticks = (k*y) + k - 1;
        ans += ceilDivision(totalSticks, x-1);
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