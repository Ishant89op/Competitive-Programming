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
    ll solve(ll x0, ll n) {
        if(n==0 || n%4 == 0) return x0;
        ll ans = x0;
        ll rem = n%4;
        if((x0)&1) {
            /*
                if x0 = 1+odd -> 2+even -> 3+even -> 4+odd -> 5+odd -> repeat
                right    left      left      right    right
                (x0) + (1 - 2 - 3 + 4 + 5 - 6 - 7 + 8 + 9....)
            */
           if(rem == 1) ans += n;
           else if(rem == 2) ans -= 1;
           else if(rem == 3) ans -= (1+n);
        } else {
            /*
                if x0 = 1+even -> 2+odd -> 3+odd -> 4+even -> 5+even -> repeat
                        left      right    right    left      left    
                (x0) + (-1 + 2 + 3 - 4 - 5 + 6 + 7 - 8 - 9....)
            */
            if(rem == 1) ans -= n;
            else if (rem == 2) ans += 1;
            else if(rem == 3) ans += 1+n;
        }
        return ans;
    }
};

signed main() {
    fastIO();

    int testCases;
    cin >> testCases;
    Solution sol;
    while (testCases--) {
        ll x0, n; 
        cin >> x0 >> n;
        cout << sol.solve(x0, n) << "\n";
    }
    return 0;
}