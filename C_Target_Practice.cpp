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
    int solve(vector<vector<char>>& grid) {
        int ans = 0;
        loop(i, 0, 10) {
            loop(j, 0, 10) {
                if(grid[i][j] == 'X') ans += addPoint(i, j);
            }
        }
        return ans;
    }
private:
    int addPoint(int i, int j) {
        if(i == 0 || i == 9 || j == 0 || j == 9) return 1;
        if(i == 1 || i == 8 || j == 1 || j == 8) return 2;
        if(i == 2 || i == 7 || j == 2 || j == 7) return 3;
        if(i == 3 || i == 6 || j == 3 || j == 6) return 4;
        if(i == 4 || i == 5 || j == 4 || j == 5) return 5;
    }
};

signed main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        vector<vector<char>> grid(10, vector<char>(10));
        loop(i, 0, 10) {
            loop(j, 0, 10) {
                cin >> grid[i][j];
            }
        }
        cout << sol.solve(grid) << "\n";
    }
    return 0;
}