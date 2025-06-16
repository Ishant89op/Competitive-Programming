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
    bool regular(string& s) {
        ll openB = 0, closeB = 0;
        loop(i, 0, s.size()) {
            if(s[i] == '(') openB++;
            else closeB++;
            if(openB < closeB) return false;
        }
        return true;
    }
public:
   // Solution() {
      
   // }

    ll solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        ll openB = 0, closeB = 0;
        ll moves = 0;
        loop(i, 0, n) {
            if(s[i] == '(') openB++;
            else closeB++;
            if(openB < closeB) {
                s.erase(i, 1);
                s.push_back(')');
                moves++;
                closeB--;
                i--;
            } 
        }
        return moves;
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