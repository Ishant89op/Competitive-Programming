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
        ll a, b;
        cin >> a >> b;
        if(a == 0) return 0;
        else if(b > a) return 1;
        else if(a == b) return 2;
        else {
            ll ans = a + 3;
            for (long long i = (b < 2 ? 2 - b : 0); i < ans; ++i) {
                long long newB = b + i;
                long long cpa = a;
                long long steps = i;

                while (cpa) {
                    cpa /= newB;
                    ++steps;
                }

                if (steps < ans) {
                    ans = steps;
                }
            }
            return ans;
        }
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