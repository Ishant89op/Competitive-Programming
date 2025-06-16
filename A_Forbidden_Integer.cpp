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
    void solve(int n, int k, int x) {
        if(x != 1) {
            cout << "YES\n" << n << "\n";
            loop(i, 0, n) cout << "1 ";
            cout << "\n";
            return;
        }
        if (k == 1 || n == 1) {
            cout << "NO\n";
            return;
        }
        
        if (n % 2 == 0) {
            cout << "YES\n" << n/2 << "\n";
            for (int i = 0; i < n/2; i++) {
                cout << "2 ";
            }
            cout << "\n";
            return;
        }
        
        if (k >= 3) {
            cout << "YES\n" << (n-3)/2 + 1 << "\n";
            cout << "3 ";
            for (int i = 0; i < (n-3)/2; i++) {
                cout << "2 ";
            }
            cout << "\n";
            return;
        }
        
        cout << "NO\n";
    }
private:
    void sumEvenOdd(int n, vi& ans) {
        if(n == 2) {
            ans.pb(2);
            return;
        } else if(n == 3) {
            ans.pb(3);
            return;
        }

        int odd = n/2;
        int even = n-odd;
        sumEvenOdd(odd, ans);
        sumEvenOdd(even, ans);
    }
};

signed main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n, x, k;
        cin >> n >> k >> x;
        sol.solve(n, k, x);
    }
    return 0;
}