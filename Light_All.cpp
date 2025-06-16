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
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n == 1) {
            if(s[0] == '0') {
                return false;
            } else {
                return true;
            }
        }
        int minLights = ceil((double)n/2);
        int lights = 0;
        loop(i, 0, n) {
            if(s[i] == '1') {
                lights++;
            }
        }
        if(lights < minLights) {
            return false;
        }
        if((s[0] == '0' && s[1] == '0') || (s[n-1] == '0' && s[n-2] == '0')) {
            return false;
        }
        
        vb lit(n, false);
        if(s[0] == '1') {
            lit[0] = true;
            lit[1] = true;
        }
        if(s[n-1] == '1') {
            lit[n-1] = true;
            lit[n-2] = true;
        }
        loop(i, 1, n-1) {
            if(s[i] == '1') {
                if(lit[i-1] == false) {
                    lit[i-1] = true;
                    lit[i] = true;
                } else {
                    lit[i] = true;
                    lit[i+1] = true;
                }
            }
        }
        loop(i, 0, n) {
            if(lit[i] == false) {
                return false;
            }
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
        sol.solve() ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}