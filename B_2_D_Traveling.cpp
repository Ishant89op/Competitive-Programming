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
    ll travelCost(ll i, ll x1, ll y1, ll j, ll x2, ll y2, ll k) {
        ll ans = 0LL;
        if(i <= k && j <= k) ans = 0LL;
        else {
            ll dx = x1 - x2;
            ll dy = y1 - y2;
            ans = llabs(dx) + llabs(dy);
        }
        return ans;
    }

public:
    ll solve() {
        ll n, k, a, b;
        cin >> n >> k >> a >> b;
        vector<pll> cord(n);
        loop(i, 0, n) {
            cin >> cord[i].first >> cord[i].second;
        }
        ll ax = cord[a-1].first, ay = cord[a-1].second, bx = cord[b-1].first, by = cord[b-1].second;
        ll ans = LONG_LONG_MAX;
        if(a <= k && b <= k) ans = 0LL; // major to major
        else if(a > k && b > k) { // minor to minor
            ll directPrice = travelCost(a, ax, ay, b, bx, by, k); // direct
            ans = directPrice;
            // a to major price
            if(k!=0) {
                ll aToClosestMajorPrice = LONG_LONG_MAX;
            loop(i, 0, k) {
                ll x2 = cord[i].first, y2 = cord[i].second;
                aToClosestMajorPrice = min(aToClosestMajorPrice, travelCost(a, ax, ay, i+1, x2, y2, k));
            }
            // major to b price
            ll closestMajorToBPrice = LONG_LONG_MAX;
            loop(i, 0, k) {
                ll x1 = cord[i].first, y1 = cord[i].second;
                closestMajorToBPrice = min(closestMajorToBPrice, travelCost(i+1, x1, y1, b, bx, by, k));
            }
            ans = min(directPrice, aToClosestMajorPrice + closestMajorToBPrice);
            }
            
        } else if(a > k && b <= k) { // minor to major
            // a to closest major
            loop(i, 0, k) {
                ll x2 = cord[i].first, y2 = cord[i].second;
                ans = min(ans, travelCost(a, ax, ay, i+1, x2, y2, k));
            }
        } else if(a <= k && b > k) { // major to minor
            // closest major to b
            loop(i, 0, k) {
                ll x1 = cord[i].first, y1 = cord[i].second;
                ans = min(ans, travelCost(i+1, x1, y1, b, bx, by, k));
            }
        }
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