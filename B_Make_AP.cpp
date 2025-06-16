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
    bool solve(ll a, ll b, ll c) {
        bool answer = false;
 
        ll new_a = 2 * b - c; // 1
        if (new_a / a > 0 && new_a % a == 0) // 1
            answer = true;
        
       ll new_b = (a + c) / 2;
        if (new_b / b > 0 && new_b % b == 0 && (c - a) % 2 == 0)
            answer = true;
 
        ll new_c = 2 * b - a;
        if (new_c / c > 0 && new_c % c == 0)
            answer = true;
 
        return answer;
    }
};

signed main() {
    fastIO();

    int testCases;
    cin >> testCases;
    Solution sol;
    while (testCases--) {
        ll a, b, c; cin >> a >> b >> c;
        sol.solve(a, b, c) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}