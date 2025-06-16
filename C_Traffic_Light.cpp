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
    ll solve(int n, char c, string& s) {
        s += s;
        if(n==1) return 0;
        vector<int> next_g(2 * n, -1);
        int last_g = -1;
        for (int i = 2 * n - 1; i >= 0; --i) {
            if (s[i] == 'g') last_g = i;
            next_g[i] = last_g;
        }
        ll max_wait = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                ll wait = next_g[i] - i;
                max_wait = max(max_wait, wait);
            }
        }
        return max_wait;
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n; char c;
        cin >> n >> c;
        string s;
        cin >> s;
        cout << sol.solve(n, c, s) << "\n";
    }
    return 0;
}