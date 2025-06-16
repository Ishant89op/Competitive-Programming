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
        int n, m , k;
        cin >> n >> m >> k;
        int total = n * m;
        int choco = 0;
        
        loop(i, 1, n) {
            int area1 = i * m;
            int area2 = total - area1;
            if (area1 >= k)
                choco = max(choco, area2);
            if (area2 >= k)
                choco = max(choco, area1);
        }
        
        loop(j, 1, m) {
            int area1 = j * n;
            int area2 = total - area1;
            if (area1 >= k)
                choco = max(choco, area2);
            if (area2 >= k)
                choco = max(choco, area1);
        }
        
        if (k == 0)
            choco = total;
        
        return choco;
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