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
    ll solve(int n, string& s) {
        int cont = 0, curr = 0;
        loop(i, 0, n) {
            if(int(s[i]-'0') != curr) {
                curr ^= 1;
                cont++;
            }
        }
        if(cont == 2) return n+cont-1;
        else if(cont > 2) return n+cont-2;
        else return n+cont;
    }
private:
    ll cost(string& s) {
        ll ans = 0;
        int button = 0;
        if(sz(s) > 0 && s[0] == '1') ans++;
        loop(i, 0, sz(s)-1) {
            if(s[i] != s[i+1]) ans++;
        }
        return sz(s) + ans;
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
        string s;
        cin >> s; 
        cout << sol.solve(n, s) << "\n";
    }
    return 0;
}