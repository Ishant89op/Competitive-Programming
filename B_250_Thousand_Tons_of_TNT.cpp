#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define sz(x) x.size()
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i >= a; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
public:
   // Solution() {
      
   // }

    ll solve() {
        int n;
        cin >> n;
        vi a(n);
        loop(i, 0, n) {
            cin >> a[i];
        }
        if(n == 1) return 0;
        vi pK;
        loop(i, 1, n+1) {
            if(n % i == 0) {
                pK.pb(i);
            }
        }
        int m = sz(pK);
        ll ans = 0;
        loop(i, 0, m) {
            int k = n/pK[i];
            ll wMin = LONG_LONG_MAX, wMax = LONG_LONG_MIN;
            for(int j = 0; j < n; j+=k) {
                ll w = 0;
                loop(l, j, j+k) {
                    w += a[l];
                }
                wMin = min(wMin, w);
                wMax = max(wMax, w);
            } 
            ans = max(ans, wMax - wMin);
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