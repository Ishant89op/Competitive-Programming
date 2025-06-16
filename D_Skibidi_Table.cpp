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
    pii findPosition(int n, ll d) {
        int row = 1, col = 1;
        ll size = (1LL << n); // (2^n)
        
        while (size > 2) {
            size /= 2;
            ll block_size = size * size;
            
            if (d <= block_size) {
                // Q-1, do nothing
            } else if (d <= 2 * block_size) {
                // Q-4
                row += size;
                col += size;
                d -= block_size;
            } else if (d <= 3 * block_size) {
                // Q-3
                row += size;
                d -= 2 * block_size;
            } else {
                // Q-2
                col += size;
                d -= 3 * block_size;
            }
        }

        if (d == 1) return {row, col};
        if (d == 2) return {row + 1, col + 1};
        if (d == 3) return {row + 1, col};
        return {row, col + 1};
    }
    
    ll getNumber(int n, int row, int col) {
        ll result = 0;
        ll size = (1LL << n); // (2^n)
        
        while (size > 2) {
            size /= 2;
            ll block_size = size * size;
            
            if (row <= size && col <= size) {
                // Q-1
            } else if (row > size && col > size) {
                // Q-4
                result += block_size;
                row -= size;
                col -= size;
            } else if (row > size && col <= size) {
                // Q-3
                result += 2 * block_size;
                row -= size;
            } else {
                // Q-2
                result += 3 * block_size;
                col -= size;
            }
        }
        
        if (row == 1 && col == 1) return result + 1;
        if (row == 2 && col == 2) return result + 2;
        if (row == 2 && col == 1) return result + 3;
        return result + 4;
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n, q;
        cin >> n >> q;

        string ques;
        for(int i = 0; i < q; i++) {
            cin >> ques;
            
            if (ques == "->") {
                ll x, y;
                cin >> x >> y;
                cout << sol.getNumber(n, x, y) << "\n";
            } else {
                ll d;
                cin >> d;
                auto [x, y] = sol.findPosition(n, d);
                cout << x << " " << y << "\n";
            }
        }
    }
    return 0;
}