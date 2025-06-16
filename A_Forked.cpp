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
    set<pair<int, int>> calc(int a, int b, int x, int y) {
        set<pii> pos;

       pos.insert({x + a, y + b});
       pos.insert({x + a, y - b});
       pos.insert({x - a, y + b});
       pos.insert({x - a, y - b});
       pos.insert({x + b, y + a});
       pos.insert({x + b, y - a});
       pos.insert({x - b, y + a});
       pos.insert({x - b, y - a});
        
        return pos;
    }
public:
    // Solution () {
          
    // }
    int solve(int a, int b, int xk, int yk, int xq, int yq) {
        set<pii> king = calc(a, b, xk, yk);
        set<pii> queen = calc(a, b, xq, yq);
        int ans = 0;
        for(auto& pos: king) {
            if(queen.find(pos) != queen.end()) ans++;
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
        int a, b, xk, yk, xq, yq;
        cin >> a >> b >> xk >> yk >> xq >> yq;
        cout << sol.solve(a, b, xk, yk, xq, yq) << "\n";
    }
    return 0;
}