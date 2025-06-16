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
    void solve(string s) {
        if(sz(s) < 2) {
            cout << "-1\n";
            return;
        }
        string ans = "";
        loop(i, 0, sz(s)-1) {
            if(s[i] == s[i+1]) {
                ans += s[i];
                ans += s[i+1];
                cout << ans << "\n";
                return;
            }
        }
        loop(i, 0, sz(s)-2) {
            if(s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2]) {
                ans += s[i]; 
                ans += s[i+1];
                ans += s[i+2];
                cout << ans << "\n";
                return;
            }
        }
        cout << "-1\n"; 
    }

private:
    int f(string p) {
        unordered_set<string> set;
        for (int i = 0; i < p.size(); ++i) {
            string current = "";
            for (int j = i; j < p.size(); ++j) {
                current += p[j];
                set.insert(current);
            }
        }
        return set.size();
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        string s;
        cin >> s;
        sol.solve(s);
    }
    return 0;
}