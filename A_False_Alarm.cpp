#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define sz(x) x.size()
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i >= a; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
public:
   // Solution() {
      
   // }

    bool solve() {
        int n, x;
        cin >> n >> x;
        vi a(n);
        int firstClosedIdx = -1, lastClosedIdx = -1;
        loop(i, 0, n) {
            cin >> a[i];
            if(firstClosedIdx == -1 && a[i] == 1) {
                firstClosedIdx = i;
            }
            if(a[i] == 1) {
                lastClosedIdx = i;
            }
        }
        int gap = lastClosedIdx - firstClosedIdx + 1;
        return gap <= x;
    }
};

signed main() {
    fastio

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        sol.solve() ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}