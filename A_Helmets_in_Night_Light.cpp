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

#define int long long
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
    ll solve(int n, int p, vi& A, vi& B) {
        ll cost = p;
        int shared = 1;
        map<int, int> m;
        loop(i, 0, n) {
            m[B[i]] += A[i];
        }
        for(auto [key, val]: m) {
            int remaining = n-shared;
            int currCost = min(p, key);
            if(val >= remaining) {
                cost += (currCost*remaining);
                break;
            } else {
                cost += (currCost*val);
                shared += val;
            }
        }
        return cost;
    }
};

signed main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n, p;
        cin >> n >> p;
        vi A(n), B(n);
        for(auto& i: A) cin >> i;
        for(auto& i: B) cin >> i;
        cout << sol.solve(n, p, A, B) << "\n";
    }
    return 0;
}