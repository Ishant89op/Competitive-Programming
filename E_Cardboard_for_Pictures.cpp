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
    ll totalCardboardArea(vll& s, ll& w, ll& c) {
        ll ans = 0;
        loop(i, 0, sz(s)) {
            ll side = s[i] + (2*w);
            ans += (side*side);
            if(ans > c) break;
        }
        return ans;
    }

public:
    ll solve() {
        ll n, c;
        cin >> n >> c;
        vll s(n);
        loop(i, 0, n) {
            cin >> s[i];
        }
        
        ll l = 1;
        ll r = 1e9;

        while(l <= r) {
            ll mid = l + ((r - l)/2);
            ll sumall = totalCardboardArea(s, mid, c);
            if(sumall == c) {
                return mid;
            }
            if(sumall > c) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return 0;
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