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
    ll solve(int n, int m, int k, string& s) {
        int i = 0, j = m-1;
        ll ans = 0;
        int idx = 0;
        vi oneIdx;
        loop(i, 0, n) if(s[i] == '1') oneIdx.pb(i);
        while(i < n && j < n) { 
            if(!check(s, i, j)) {
                ans++;
                i+=m+k-1; j+=m+k-1;
                continue;
            }
            i++; j++; 
        }

        return ans;
    }
private:
    bool check(string& s, int i, int j) {
        loop(idx, i, j+1) {
            if(s[idx] == '1') return true;
        }
        return false;
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        cout << sol.solve(n, m, k, s) << "\n";
    }
    return 0;
}