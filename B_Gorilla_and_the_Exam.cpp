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
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)

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
    int solve(int n, int k, vll& A) {
        if(n==1 || k >= n-1) return 1;
        int opr = 0;
        sort(all(A));
        
        
        vi segLen;
        ll current = A[0];
        int len = 1;
        for(int i = 1; i < n; i++) {
            if(A[i] != current) {
                segLen.pb(len);
                current = A[i];
                len = 1;
            } else {
                len++;
            }
        }
        segLen.pb(len);
        
        sort(all(segLen));

        int tillIndex = -1;
        rep(i, 0, segLen.size()) {
            if(k > 0 && k >= segLen[i]) {
                tillIndex = i;
                k -= segLen[i];
            }
        }

        opr = 1 + segLen.size() - (tillIndex+2);
        
        return opr;
   }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vll A(n);
        for(auto& i : A) cin >> i;
        cout << sol.solve(n, k, A) << endl;
    }
    return 0;
}