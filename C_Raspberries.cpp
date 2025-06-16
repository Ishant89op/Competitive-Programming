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
    int solve() {
        int n, k; cin >> n >> k;
        vi A(n); 
        int ans = INF;
        int even = 0;
        bool rem0 = false;
        for(auto& i: A) {
            cin >> i;
            int rem = i%k;
            if(!(i&1)) even++;
            if(rem == 0) {
                rem0 = true;
            }
            if(i < k) ans = min(ans, k-i);
            else {
                ans = min(ans, k - rem);
            }
        }
        
        if(rem0) return 0;
        
        if(k!=4) return ans;
        else {
            if(even <= 2) return min(2-even, ans);
            else return 0;
        }
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