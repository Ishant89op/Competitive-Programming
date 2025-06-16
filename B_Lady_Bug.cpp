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
    bool solve(int n, string& a, string& b) {
        string f, s;
        rep(i, 0, n) {
            if(i%2==0) {
                f += a[i];
                s += b[i];
            } else {
                s += a[i];
                f += b[i];
            }
        }
        int zeroesInS = count(all(s), '0');
        int zeroesInF = count(all(f), '0');
        int aInF = n%2==0 ? n/2 : n/2+1;
        int aInS = n/2;
        return (zeroesInF >= aInF && zeroesInS >= aInS);
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        sol.solve(n, a, b) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}