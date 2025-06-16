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

    int solve() {
        int n;
        cin >> n;
        vi a(n);
        loop(i, 0, n) {
            cin >> a[i];
        }
        if(n == 1) return a[0];
        // vb acceptables(n, true);
        // loop(i, 0, n-1) {
        //     if((a[i] & 1) == (a[i+1] & 1)) {
        //         if(a[i] >= a[i+1]) {
        //             acceptables[i+1] = false;
        //         } else {
        //             acceptables[i] = false;
        //         }
        //     }
        // }
        int ans = a[0];
        int mn = min(0, a[0]), sum = a[0];
        loop(i, 1, n) {
            if(abs(a[i] & 1) == abs(a[i - 1] & 1)) {
                mn = 0;
                sum = 0;
            }
            sum += a[i];
            ans = max(ans, sum - mn);
            mn = min(mn, sum);
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