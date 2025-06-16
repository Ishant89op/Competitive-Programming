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
    int solve(string& s, string& t) {
        // last -> 00, 50, 75, 25;
        int sptr = s.length() - 1;

        int ans = 0;
        while (sptr >= 0 && s[sptr] != t[1])
        {
            sptr--;
            ans++;
        }

        if (sptr < 0) return INF;

        sptr--;

        while (sptr >= 0 && s[sptr] != t[0])
        {
            sptr--;
            ans++;
        }

        return sptr < 0 ? INF : ans;
    }
};

signed main() {
    fastIO();

    int testCases;
    cin >> testCases;
    Solution sol;
    vector<string> sub = {"00", "25", "50", "75"};
    while (testCases--) {
        string n;
        cin >> n;
        int ans = INF;
        for(auto t: sub) ans = min(ans, sol.solve(n, t));
        cout << ans << "\n";
    }
    return 0;
}