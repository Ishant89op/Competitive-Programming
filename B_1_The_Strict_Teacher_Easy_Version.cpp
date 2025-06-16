#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
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
    ll solve(int n, int m, int q, int pT1, int pT2, int pD) {
        ll moves = 0;
        if(pD < pT1 && pD < pT2) moves = pT1 < pT2 ? pT1-1 : pT2-1;
        else if(pD > pT1 && pD > pT2) moves = pT1 < pT2 ? n-pT2 : n-pT1;
        else moves = (abs(pT1-pT2))/2;
        return moves;
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n, m, q;
        cin >> n >> m >> q;
        int pT1, pT2, pD;
        cin >> pT1 >> pT2 >> pD;
        cout << sol.solve(n, m, q, pT1, pT2, pD) << "\n";
    }
    return 0;
}