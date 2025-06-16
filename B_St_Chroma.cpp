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
    void solve(int n, int x) {
        if(n == 1) {
            cout << "0\n";
            return;
        }
        vi ans;
        if(x == 0 || x >= n) {    
            loop(i, 0, n) ans.pb(i);
            swap(ans[0], ans[n-1]);
        } else {
            loop(i, 0, x) ans.pb(i);
            rloop(i, n, x+1) ans.pb(i);
            ans.pb(x);
        }

        for(auto i: ans) cout << i << " ";
        cout << "\n";
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n, x;
        cin >> n >> x;
        sol.solve(n, x);
    }
    return 0;
}