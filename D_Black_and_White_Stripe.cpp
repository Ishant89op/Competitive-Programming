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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int maxB = 0, B = 0;
        loop(j, 0, k) {
            if(s[j] == 'B') B++;
        }
        maxB = max(B, maxB);
        loop(i, 1, n-k+1) {
            if(s[i-1] == 'B') B--;
            if(s[i+k-1] == 'B') B++;
            maxB = max(B, maxB);
        }
        return k-maxB;
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