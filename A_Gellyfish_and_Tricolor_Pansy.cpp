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

    ll solve() {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll gfTurns = min(b, d);
        ll fTurns = min(a, c);
        if(gfTurns <= fTurns) {
            return true;
        } else {
            return false;
        }
    }
};

signed main() {
    fastio

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        sol.solve() ? cout << "Gellyfish\n" : cout << "Flower\n";
    }
    return 0;
}