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
    void solve(vector<vector<char>>& grid) {
        vpii A, B, C;
        loop(i, 0, 3) {
            loop(j, 0, 3) {
                if(grid[i][j] == 'A') A.pb({i, j});
                else if (grid[i][j] == 'B') B.pb({i, j});
                else C.pb({i, j}); 
            }
        }
        vector<string> templates = {
            "AAA", "AAB", "AAC", "ABA", "ABB", "ABC", "ACA", "ACB", "ACC",
            "BAA", "BAB", "BAC", "BBA", "BBB", "BBC", "BCA", "BCB", "BCC",
            "CAA", "CAB", "CAC", "CBA", "CBB", "CBC", "CCA", "CCB", "CCC"
        };

        string ans = "ZZZ";

        for (auto& temp : templates) {
            vpii first, second, third;

            if (temp[0] == 'A') first = A;
            else if (temp[0] == 'B') first = B;
            else first = C;

            if (temp[1] == 'A') second = A;
            else if (temp[1] == 'B') second = B;
            else second = C;

            if (temp[2] == 'A') third = A;
            else if (temp[2] == 'B') third = B;
            else third = C;

            for (auto& p1 : first) {
                int r1 = p1.first, c1 = p1.second;
                for (auto& p2 : second) {
                    int r2 = p2.first, c2 = p2.second;
                    if (r1 == r2 && c1 == c2) continue;
                    if (!adjacent(r1, c1, r2, c2)) continue;

                    for (auto& p3 : third) {
                        int r3 = p3.first, c3 = p3.second;
                        if ((r3 == r1 && c3 == c1) || (r3 == r2 && c3 == c2)) continue;
                        if (!adjacent(r2, c2, r3, c3)) continue;

                        string formed;
                        formed += grid[r1][c1];
                        formed += grid[r2][c2];
                        formed += grid[r3][c3];

                        if (formed < ans) {
                            ans = formed;
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
private:
    bool adjacent(int r, int c, int r1, int c1) {
        return ((r1 == r && (c1 == c+1 || c1 == c-1)) || (r1 == r-1 && (c1 == c+1 || c1 == c || c1 == c-1)) || (r1 == r+1 && (c1 == c-1 || c1 == c || c1 == c+1)));
    }
};

signed main() {
    fastIO();

    Solution sol;
    vector<vector<char>> grid(3, vector<char>(3));
    loop(i, 0, 3) {
        loop(j, 0, 3) {
            cin >> grid[i][j];
        }
    }
    sol.solve(grid);
    return 0;
}