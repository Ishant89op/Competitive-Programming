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

vll dp(300000+5);
void calc() {
    dp[0] = 0;
    loop(i, 1, 300005) {
        dp[i] = (dp[i-1] ^ i);
    }
}

class Solution {
public:
   // Solution() {
      
   // }

    ll solve() {
        ll a, b; 
        cin >> a >> b;
        ll ans = a;
        ll xo = dp[a-1];
        
        if(xo == b) {
            return ans;
        } else if(xo != b && (xo^b) != a) {
            return ans + 1;
        } else if(xo != b && (xo^b) == a) {
            return ans + 2;
        } else {
            return -1;
        }
    }
};

signed main() {
    fastio

    calc();
    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        cout << sol.solve() << "\n";
    }
    return 0;
}