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
    void solve(int n, string& s, string& t) {
        if(n == 0) {
            cout << "-1\n";
            return;
        }
        if(s==t) {
            cout << "0\n";
            return;
        }
        if(s[0] != t[0]) {
            cout << "-1\n";
            return;
        }
        vector<int> ops;
        
        loop(i, 0, 3) {
            bool flag = true;
            rloop(i, n, 1) {
                if(s[i] != t[i]) {
                    flag = false;
                    if(s[i-1] == '1') {
                        if(s[i] == '0') s[i] = '1';
                        else s[i] = '0'; 
                        ops.pb(i);
                    }
                }
            }
            if(flag) break;
        }

        
        if(s==t) {
            cout << sz(ops) << endl;
            if (!ops.empty()) {
                for (int idx : ops) {
                    cout << idx << " ";
                }
                cout << endl;
            }
        } else {
            cout << "-1\n";
            return;
        }
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
        string s, t;
        cin >> s >> t;
        sol.solve(n, s, t);
    }
    return 0;
}