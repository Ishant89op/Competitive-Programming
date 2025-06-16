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
    ll solve(int n, int k, ll x, vi A, ll arrSum) {
        if(arrSum*k < x) return 0;
        if(arrSum == x) return 1;
        ll ans = 0;
        ll totalElements = n*k;
        ll sum = 0;
        ll no = 0;
        per(i, 0, n*k) {
            if(sum >= x) break;
            sum += A[(n - 1 - (i % n))];
            no++; 
        }
        ans = totalElements - no;
        return ans+1;
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n, k;
        ll x;
        cin >> n >> k >> x;
        vi A(n);
        ll arrSum = 0;
        for(auto& val : A) {
            cin >> val;
            arrSum += val;
        }
        cout << sol.solve(n, k, x, A, arrSum) << endl;
    }
    return 0;
}