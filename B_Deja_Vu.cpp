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
    int countPowersOf2(int e) {
        int ans = 0;
        while(!(e&1) && e > 0) {
            ans++;
            e >>= 1;
        }
        return ans;
    }
public:
   // Solution() {
      
   // }

    void solve() {
        int n, q;
        cin >> n >> q;
        vi a(n), x(q);
        vi pow2(n);
        loop(i, 0, n) {
            cin >> a[i];
            pow2[i] = countPowersOf2(a[i]);
        }
        loop(i, 0, q) {
            cin >> x[i];
        }
        sort(all(x));
        loop(i, 0, n) {
            loop(j, 0, q) {
                int currPower = pow2[i];
                if(currPower >= x[j]) {
                    int k = x[j] - 1;
                    int add = (1 << k);
                    a[i] += add;
                    if(k < currPower) {
                        pow2[i] = k;
                    }
                } else {
                    if(j != q-1 && a[j] != a[j+1]) {
                        break;
                    } 
                }
            }
        } 
        loop(i, 0, n) {
            cout << a[i] << " ";
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