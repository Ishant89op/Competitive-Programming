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
    bool solve(int n, int k, vi& A, ll sum) {
        int MAX = *max_element(all(A));
        int MIN = *min_element(all(A));
        sort(all(A));
        int minIdx = 0;
        bool turn = true;
        if(MAX - MIN + 1 <= k) return false;
        while(MAX - MIN + 1 > k && minIdx < n) {
            turn = turn ? false : true;
            A[minIdx]--;
            if(A[minIdx] == 0) minIdx++;
            if(MAX - MIN <= k) return turn;
        }
        return !turn;
    }
};

signed main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vi A(n);
        ll sum = 0;
        for(auto& i: A) {
            cin >> i;
            sum += i;
        }
        sol.solve(n, k, A, sum) ? cout << "Tom\n" : cout << "Jerry\n";
    }
    return 0;
}