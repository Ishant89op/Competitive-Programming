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
    void solve(int n, vector<vi>& G) {
        vi ans;
        ll sum = 0;
        loop(i, 0, n) {
            ans.push_back(G[i][0]);
            sum += G[i][0];
        }
        loop(i, 1, n) {
            ans.push_back(G[n-1][i]);
            sum += G[n-1][i];
        }
        ll totalSum = n*(2*n + 1);
        int lastNum = totalSum - sum;
        ans.insert(ans.begin(), lastNum);
        for(auto i: ans) cout << i << " ";
        cout << "\n";
    }

private:
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n;
        cin >> n;
        vector<vi> G(n, vi(n, 0));
        loop(i, 0, n) {
            loop(j, 0, n) {
                cin  >> G[i][j];
            }
        } 
        sol.solve(n, G);
    }
    return 0;
}