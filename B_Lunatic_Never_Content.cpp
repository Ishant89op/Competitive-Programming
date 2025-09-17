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
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair
#define sz(x) x.size()
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i >= a; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {

public:
    ll solve() {
        int n;
        cin >> n;
        vi a(n);
        loop(i, 0, n) {
            cin >> a[i];
        }
        if(n==1) return 0;
        ll x = 0;
        /*
            a % x = b % x
            
            a % x = px + r
            b % x = qx + r

            a - b = (p-q)*x

            (a-b)/x = (p-q)
            
            this is the congruence relation, means that 'x' divides '(a-b)'.
        */
        loop(i, 0, n/2) {
            int num = abs(a[i] - a[n-i-1]);
            x = gcd(x, num);
        }

        return x;
    }
};

signed main() {
    fastio

    int T = 1;
    cin >> T;
    Solution sol;

    while (T--) {
        cout << sol.solve() << "\n";
    }
    return 0;
}