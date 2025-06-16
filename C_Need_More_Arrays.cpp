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

    int solve() {
        int n;
        cin >> n;
        vi a(n);
        for(auto& i: a) {
            cin >> i;
        }
        int ans = 0, last = -2;
        loop(i, 0, n) {
            if (a[i] > last + 1) {
                ans++;
                last = a[i];
            }
        }
        return ans;
    }
};

signed main() {
    fastio

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        cout << sol.solve() << "\n";
    }
    return 0;
}