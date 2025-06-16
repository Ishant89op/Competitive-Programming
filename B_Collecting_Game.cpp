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

    void solve() {
        ll n; 
        cin >> n;
        pii a[n + 1];
        loop(i, 1, n+1) {
            cin >> a[i].first; 
            a[i].second = i;
        }
        sort(a + 1, a + n + 1);
        int nxt[n + 1];
        ll sum[n + 1];
        int ans[n + 1];
        nxt[0] = sum[0] = 0;
        loop(i, 1, n+1) {
            if(nxt[i - 1] >= i) {
                nxt[i] = nxt[i - 1];
                sum[i] = sum[i - 1];
            } else {
                sum[i] = sum[i - 1] + a[i].first;
                nxt[i] = i;
                while(nxt[i] + 1 <= n && sum[i] >= a[nxt[i] + 1].first) {
                    nxt[i]++;
                    sum[i] += a[nxt[i]].first;
                }
            }
            ans[a[i].second] = nxt[i];
        }

        loop(i, 1, n+1) {
            cout << ans[i]-1 << " ";
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