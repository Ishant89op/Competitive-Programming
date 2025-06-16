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
    int solve(int n, int m, string& x, string& s) {
        int ans = 0;
        if(sz(x) < sz(s)) {
            while(sz(x) < sz(s)) { 
                x += x;
                ans++;
            }
        }
        if(KMP(x, s)) return ans;
        while(sz(x) <= 2*sz(s) || ans < 2) {
            x += x;
            ans++;
            if(KMP(x, s)) return ans;
        }
        return -1;
    }
private:
    bool KMP(string s1, string s2) {
       // Knuth-Morris-Pratt Algorithm for Optimized String Matching
       // s1 = text // s2 = pattern
       // TC = O(n) // SC = O(n+m) 
        vector<int> ans, LPS(s2.size(), 0);
        int len = 0, i = 1, j = 0;
    
        while (i < s2.size()) {
            if (s2[i] == s2[len]) LPS[i++] = ++len;
            else if (len) len = LPS[len - 1];
            else LPS[i++] = 0;
        }
    
        for (i = 0; i < s1.size();) {
            if (s2[j] == s1[i]) i++, j++;
            if (j == s2.size()) ans.push_back(i - j), j = LPS[j - 1];
            else if (i < s1.size() && s2[j] != s1[i]) j ? j = LPS[j - 1] : i++;
        }
    
        return sz(ans) > 0;
    }
};

signed main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
        cout << sol.solve(n, m, x, s) << "\n";
    }
    return 0;
}