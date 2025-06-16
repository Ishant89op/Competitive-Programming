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
    ll solve(int n, ll k, vll& A, vll& B, int miss) {
        ll Amax = *max_element(all(A));
        ll Amin = *min_element(all(A));
        if(miss < n) {
            ll x = -1;
            loop(i, 0, n) {
                if(x != -1 && B[i] != -1) if(A[i]+B[i] != x) return 0; 
                if(x == -1 && B[i] != -1) x = A[i]+B[i];
            }
            if(k < x-Amin || x < Amax) return 0; 
            return 1;
        }
        ll x_min = Amax, x_max = Amin+k;
        return x_max-x_min+1;
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;
        vll A(n), B(n);
        int miss = 0;
        for(auto& i: A) cin >> i;
        for(auto& i: B) {
            cin >> i;
            if(i==-1) miss++;
        }
        cout << sol.solve(n, k, A, B, miss) << "\n";
    }
    return 0;
}