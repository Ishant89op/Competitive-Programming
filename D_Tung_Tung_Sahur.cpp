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
    bool solve(string& p, string& s) {
        int i = 0, j = 0;
        int n = p.size(), m = s.size();
        while (i < n || j < m) {
            if(i == n || j == m || p[0] != s[0]) return false;

            int st1 = i, st2 = j;
            while(i < n && p[i] == p[st1]) i++;
            while(j < m && s[j] == s[st2]) j++;

            if(j-st2 < i-st1 || (i-st1)*2 < j-st2) return false;
        }
        return true;
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        string p, s;
        cin >> p >> s;
        sol.solve(p, s) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}