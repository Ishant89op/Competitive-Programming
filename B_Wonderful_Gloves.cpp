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
    ll solve(int n, int k, vll& l, vll& r, ll total) {
        ll sum = 0;
        vector<int> min_lr;
        loop(i, 0, n) {
            if(l[i] < r[i]) {
                sum += r[i];
                min_lr.pb(l[i]);
            } else {
                sum += l[i];
                min_lr.pb(r[i]);
            }
        }
        sort(rall(min_lr));
        loop(i, 0, k-1) sum += min_lr[i];
        return sum+1;
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
        vll l(n), r(n);
        ll total = 0;
        for(auto& i: l) {
            cin >> i;
            total += i;
        }
        for(auto& i: r) {
            cin >> i;
            total += i;
        }
        cout << sol.solve(n, k, l, r, total) << "\n";
    }
    return 0;
}