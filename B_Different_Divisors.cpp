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
    bool prime(ll num) {
        if(num <= 1) return false;
        else if(num <= 3) return true;
        for(int i = 2; i*i <= num; i++) {
            if(num % i == 0) return false;
        }
        return true;
    }

    ll nearestPrime(ll n) {
        ll i = n + 1;
        while(!prime(i)) {
            if(i&1) i += 2;
            else i++;
        }
        return i;
    }

public:
   // Solution() {
      
   // }

    ll solve() {
        ll d;
        cin >> d;
        ll x = d+1;
        ll p = nearestPrime(d);
        ll minQ = p+d;
        ll q = nearestPrime(minQ-1);
        ll ans = min(p*p*p, p*q);
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