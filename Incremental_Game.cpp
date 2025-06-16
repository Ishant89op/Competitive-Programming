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
    bool solve() {
        int x, y, k;
        cin >> x >> y >> k;
        
        if (x < y) {
            swap(x, y);
        }
        
        if (k >= y) {
            return true;
        }
        
        if (x == y) {
            return (2 * k >= x);
        }
        
        if (x == y + k) {
            return false;
        }
        
        int diff = x - y;
        if (diff % (k + 1) == 0) {
            return false;
        }
        
        return true;
    }
};

signed main() {
    fastio

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        sol.solve() ? cout << "Alice\n" : cout << "Bob\n";
    }
    return 0;
}