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

    void solve() {
        string s;
        cin >> s;
        int num = stoi(s);
        float sqroot = sqrt(num);
        if(floor(sqroot) != ceil(sqroot)) {
            cout << "-1\n";
            return;
        } else {
            if(sqroot == 0) {
                cout << 0 << " " << 0 << "\n";
                return;
            }
            cout << sqroot-1 << " " << 1 << "\n";
            return;
        }
    }
};

signed main() {
    fastio

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        sol.solve();
    }
    return 0;
}