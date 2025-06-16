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
        int n;
        cin >> n;
        int x = 0;
        while(pow(2, x) < n) {
            x++;
        } 
        int y = pow(2, x-1);
        int z = y-1;
        while(z >= 0) {
            cout << z-- << " ";
        }
        while(y < n) {
            cout << y++ << " ";
        }
        cout << "\n";
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