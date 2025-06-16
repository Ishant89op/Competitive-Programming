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
    ll solve(int n, vll& A, int k, int l, int r) {
        return f(k, A, l, r);
    }

private:
    ll f(ll k, const vll& a, int l, int r) {
        long long ans = 0;
        for (int i = l; i <= r; ++i) {
            while (k % a[i] == 0) {
                k /= a[i];
            }
            ans += k;
        }
        return ans;
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vll A(n);
        for(auto& val: A) cin >> val;
        while(q--) {
            int k, l, r;
            cin >> k >> l >> r;
            cout << sol.solve(n, A, k, l, r) << "\n";
        }
    }
    return 0;
}