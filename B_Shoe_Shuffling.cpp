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
        vi A(n);
        unordered_map<int, int> uMap;
        loop(i, 0, n) {
            cin >> A[i];
            uMap[A[i]]++;
        }
        for(auto [key, val]: uMap) {
            if(val == 1) {
                cout << "-1\n";
                return;
            }
        }
        int i = 0, j = 0, x = 0;
        while(i < n && j < n) {
            while(i < n && j < n && A[i] == A[j]) {
                j++;
                x++;
            }
            int gap = j-i;
            int v = x;
            cout << v << " ";
            v -= (gap-1);
            if(v <= 0) v = 1; 
            loop(i, 0, gap-1) {
                cout << v++ << " ";
            }
            i = j; 
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