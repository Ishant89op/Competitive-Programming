#include <bits/stdc++.h>
using namespace std;

typedef short int sint;
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
    sint solve(sint n, vector<sint>& A) {
        sint ans = 0;
        sint ones = count(all(A), 1);
        sint mOnes = n-ones;
        if(ones < mOnes) {
            float gap = mOnes-ones;
            ans += ceil(gap/2);
            mOnes -= ans;
            ones += ans;
        }
        if(mOnes%2 != 0) {
            ans++;
            mOnes--;
            ones++;
        }
        return ans;
    }
};

signed main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        sint n;
        cin >> n;
        vector<sint> A(n);
        for(auto& i: A) cin >> i;
        cout << sol.solve(n, A) << "\n";
    }
    return 0;
}