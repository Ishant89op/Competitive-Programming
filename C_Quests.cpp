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
        int n, k;
        cin >> n >> k;
        vi a(n), b(n);
        int maxA = 0, maxB = 0;
        loop(i, 0, n) {
            cin >> a[i];
            if(a[i] > maxA) {
                maxA = a[i];
            }
        }
        loop(i, 0, n) {
            cin >> b[i];
            if(b[i] > maxB) {
                maxB = b[i];
            }
        }
        if(k == 1) {
            return a[0];
        }
        ll maxAns = 0, ans = 0;
        int localMaxB = b[0];
        loop(i, 0, min(n, k)) {
            ans += a[i];
            if(b[i] > localMaxB) {
                localMaxB = b[i];
            }    
            ans += localMaxB*(k-i-1);
            if(ans > maxAns) {
                maxAns = ans;
            }
            ans -= localMaxB*(k-i-1);
        }
        return maxAns;
    }
};

signed main() {
    fastio

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        cout <<sol.solve() <<"\n";
    }
    return 0;
}