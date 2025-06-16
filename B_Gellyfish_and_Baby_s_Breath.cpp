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
    const ll MOD = 998244353;
public:
   // Solution() {
      
   // }

    void solve() {
        ll n;
        cin >> n;
        vll p(n), q(n), r(n);
        loop(i, 0, n) {
            cin >> p[i];
        }
        loop(i, 0, n) {
            cin >> q[i];
        }

        loop(i, 0, n) {
            ll maxVal = 0;
            loop(j, 0, i+1) {
                ll val = (1LL << p[j]) + (1LL << q[i-j]);
                maxVal = max(maxVal, val);
            }
            r[i] = (maxVal)%MOD;
        }

        for(auto& i: r) {
            cout << i << " ";
        }
        cout << "\n";
    }
};

signed main() {
    fastio

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        sol.solve();
    }
    return 0;
}