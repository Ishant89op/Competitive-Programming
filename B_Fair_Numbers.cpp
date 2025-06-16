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
    bool fair(ll num) {
        ll n = num;
        while(n > 0) {
            ll digit = n % 10;
            if(digit != 0 && num % digit != 0) return false;
            n /= 10;
        }
        return true;
    }
public:
   // Solution() {
      
   // }

    ll solve() {
        ll n;
        cin >> n;
        if(n <= 10) {
            return n;
        }
        while(!fair(n)) {
            n++;
        }
        return n;
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