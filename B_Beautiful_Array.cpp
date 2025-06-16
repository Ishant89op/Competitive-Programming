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
        ll n, k, b, s;
        cin >> n >> k >> b >> s;
        ll minS = k*b; 
        ll maxS = k*b + n*(k-1);
        if(s < minS || s > maxS) {
            cout << "-1\n";
            return;
        }
        ll lastE = k*b;
        if(s > lastE && s <= lastE+(k-1)) {
            lastE = s;
        } else if(s > lastE+(k-1)) {
            lastE += k-1;
        }
        cout << lastE << " ";
        ll rem = s-lastE;
        ll i = 2;
        while(i <= n && rem > 0) {
            cout << min(rem, k-1) << " ";
            rem -= (k-1);
            i++;
        }
        while(i <= n) {
            cout << 0 << " ";
            i++;
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