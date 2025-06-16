#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int INF = 1e9 + 5;
const ll LLINF = 1e18 + 5;
const int MOD = 1000000007;
const int MAX_N = 2e5 + 5;
const double EPS = 1e-9;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rloop(i, b, a) for (int i = (b) - 1; i >= (a); --i)

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
}

class Solution {
public:
    // Solution () {
          
    // }
    ll solve() {
        ll n, k, q;
        cin >> n >> k >> q;
        vll A(n);
        vll greaterQ;
        if(n < k) return 0;
        loop(i, 0, n) { 
            cin >> A[i];
            if(A[i] > q) greaterQ.pb(i);
        }
        ll m = sz(greaterQ);
        if(m == 0) {
            return ((n-k+1)*(n-k+2))/2;
        }
        ll ans = 0;
        ll days = greaterQ[0];
        if(days >= k) ans += ((days - k + 1)*(days - k + 2))/2;
        loop(i, 1, m) {
            days = greaterQ[i]-greaterQ[i-1]-1; 
            if(days >= k) ans += ((days - k + 1)*(days - k + 2))/2;
        }
        days = n - greaterQ[m-1] - 1; 
        if(days >= k) ans += ((days - k + 1)*(days - k + 2))/2;

        return ans;
    }
};

signed main() {
    fastIO();

    int testCases;
    cin >> testCases;
    Solution sol;
    while (testCases--) cout << sol.solve() << "\n";
    return 0;
}