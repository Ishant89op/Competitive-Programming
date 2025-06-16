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
    ll divide2k(ll n, ll k) {
        return n >> k;
    }
    ll mulitply2k(ll n, ll k) {
        return n << k;
    }
public:
   // Solution() {
      
   // }

    ll solve() {
        ll a, b;
        cin >> a >> b;
        if(a==b) return 0;
        if((a < b && !(a&1) && b&1) || (a&1 && b&1)) {
            return -1;
        }
        ll opr = 0;
        ll x = 0, y = 0, ra = a, rb = b;
        while(a % 2 == 0) {
            a /= 2;
            x++;
            ra = a;
        }
        while(b % 2 == 0) {
            b /= 2;
            y++;
            rb = b;
        }
        if(ra != rb) {
            return -1;
        }
        ll ans = ceil((double)((abs)(x-y))/3);
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