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

const int N = 30+3, K = 50+3;
int dp[N][N][K];
void fill_DP() {
    rep(i, 0, N) {
        rep(j, 0, N) {
            rep(k, 0, K) {
                if(k > i*j) {
                    dp[i][j][k] = INF;
                    continue;
                }
                if(k == 0 || k == i*j) {
                    dp[i][j][k] = 0;
                    continue;
                }
                
                dp[i][j][k] = INF;

                rep(i1, 1, i) {
                    rep(k1, 0, k+1) {
                        int i2 = i - i1, k2 = k - k1;
                        dp[i][j][k] = min(dp[i][j][k], dp[i1][j][k1] + dp[i2][j][k2] + j*j);
                    }
                }
                rep(j1, 1, j) {
                    rep(k1, 0, k+1) {
                        int j2 = j - j1, k2 = k - k1;
                        dp[i][j][k] = min(dp[i][j][k], dp[i][j1][k1]+dp[i][j2][k2] + i*i);
                    }
                }
            }
        }
    }   
}

class Solution {
public:
    // Solution () {
          
    // }
    int solve(int n, int m, int k) {
        return dp[n][m][k];
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    fill_DP();
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << sol.solve(n, m, k) << "\n";
    }
    cout << endl;
    return 0;
}