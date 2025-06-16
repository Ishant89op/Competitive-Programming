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
    int solve(int n) {
        // if(n==0 || n==1 || n==2) return n;
        // if(n==3 || n==4) return 2;
        // int minFirstTypeOpr = 1, range = 1;
        // while(1) {
        //     range = (range+1)*2;
        //     minFirstTypeOpr++;
        //     if(n < range) break;
        // }
        
        // return minFirstTypeOpr;
        if(n <= 2) return n;  // For n = 0, 1, 2.
        // For n = 3, 4: log2((n+2)/3) <= log2(6/3) = log2(2) = 1, so ceil(1) + 1 yields 2.
        return static_cast<int>(ceil(log2((n + 2) / 3.0)) + 1);
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
        cout << sol.solve(n) << endl;
    }
    return 0;
}