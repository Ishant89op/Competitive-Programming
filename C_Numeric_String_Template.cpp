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
    bool solve(int n, vi& A, string& s) {
        int sLen = sz(s);
        if(n != sLen) return false;
        map<char, int> m1;
        map<int, char> m2;
        loop(i, 0, n) {
            if(m1.find(s[i]) == m1.end() && m2.find(A[i]) == m2.end()) {
                m1[s[i]] = A[i];
                m2[A[i]] = s[i];
            } else if((m1.find(s[i]) != m1.end() && m1[s[i]] != A[i]) || (m2.find(A[i]) != m2.end() && m2[A[i]] != s[i])) {
                return false;
            }
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
        int n;
        cin >> n;
        vi A(n);
        for(auto& val: A) cin >> val;
        int m;
        cin >> m;
        vector<string> str(m);
        for(auto& s: str) cin >> s;
        for(auto s: str) sol.solve(n, A, s) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}