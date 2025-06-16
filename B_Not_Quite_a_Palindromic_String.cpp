#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;

#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i >= a; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
public:
   // Solution() {
      
   // }

    bool solve() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        
        int z = 0, o = 0;
        for (char c : s) {
            if (c == '0') z++;
            else o++;
        }
        
        int tp = n/2;
        int mg = z/2 + o/2;
        
        if (k > mg) {
            return false;
        }
        
        int bp = tp - k;
        
        bool ok = false;
        
        for (int zg = 0; zg <= min(z/2, k); zg++) {
            int og = k - zg;
            if (og > o/2) continue;
            
            int rz = z - 2*zg;
            int ro = o - 2*og;
            
            if (min(rz, ro) >= bp) {
                ok = true;
                break;
            }
        }
        
        return ok;
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