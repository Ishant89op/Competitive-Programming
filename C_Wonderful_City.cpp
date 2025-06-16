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
    ll solve(int n, vector<vll>& h, vll& a, vll& b) {
        ll coins = 0;
        if(checkBeauty(h)) return coins;
        loop(i, 0, n-1) {
            loop(j, 0, n-1) {
                if(h[i][j] == h[i+1][j]) {
                    coins += a[]
                }
            }
        }
    }
private:
    bool checkBeauty(vector<vll>& h) {
        loop(i, 0, sz(h)-1) {
            loop(j, 0, sz(h)-1) {
                if(h[i][j] == h[i+1][j] || h[i][j] == h[i][j+1]) return false;
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
        vector<vll> h(n, vll(n, 0));
        vll a(n), b(n);
        loop(i, 0, n) {
            loop(j, 0, n) {
                cin >> h[i][j];
            }
        }
        for(auto& i: a) cin >> i;
        for(auto& i: b) cin >> i;
        cout << sol.solve(n, h, a, b) << "\n";
    }
    return 0;
}