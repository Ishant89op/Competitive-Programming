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
        ll n, x;
        cin >> n >> x;
        vll A(n);
        for(auto& i: A) {
            cin >> i;
        }

        //    | v - ai | <= x
        // => -x <= v - ai <= x
        // => ai - x <= v <= ai + x

        vector<pair<ll, ll>> range(n);
        loop(i, 0, n) {
            range[i].first = A[i]-x;
            range[i].second = A[i]+x;
        }
        pair<ll, ll> current = range[0];
        ll ans = 0;
        for(ll i = 1; i < n; ++i) {
            current.first = max(current.first, range[i].first);
            current.second = min(current.second, range[i].second);

            if(current.first > current.second) {
                current = range[i];
                ans++;
            }
        }
        return ans;
    }
};

signed main() {
    fastio;

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        cout << sol.solve() << "\n";
    }
    return 0;
}