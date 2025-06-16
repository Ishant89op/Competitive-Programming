#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;

#define all(v) v.begin(), v.end()
#define sz(x) (x).size()
#define pb push_back
#define mp make_pair
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i >= a; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
    float doubledAOT(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
        return abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    }

public:
   // Solution() {
      
   // }

    ll solve() {
        ll w, h; 
        cin >> w >> h;
        ll hp1, hp2, vp1, vp2;
        cin >> hp1;
        vll h1(hp1);
        for(auto& i: h1) {
            cin >> i;
        }
        cin >> hp2;
        vll h2(hp2);
        for(auto& i: h2) {
            cin >> i;
        }
        cin >> vp1;
        vll v1(vp1);
        for(auto& i: v1) {
            cin >> i;
        }
        cin >> vp2;
        vll v2(vp2);
        for(auto& i: v2) {
            cin >> i;
        }
        vll ansv;
        ll bottomBase = h1[sz(h1)-1] - h1[0];
        ll topBase = h2[sz(h2)-1] - h2[0];
        ll leftBase = v1[sz(v1)-1] - v1[0];
        ll rightBase = v2[sz(v2)-1] - v2[0];
        ansv.pb(bottomBase);
        ansv.pb(topBase);
        ansv.pb(leftBase);
        ansv.pb(rightBase);
        ll ans = 0;
        loop(i, 0, 4) {
            if(i == 0 || i == 1) {
                ans = max(ans, ansv[i]*h);
            } else {
                ans = max(ans, ansv[i]*w);
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