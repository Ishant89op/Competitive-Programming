#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int INF = 1e9 + 5;
const ll LLINF = 1e18 + 5;
const int MOD = 1000000007;
const int MAX_N = 2e5 + 5;
const double EPS = 1e-9;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rloop(i, b, a) for (int i = (b) - 1; i >= (a); --i)

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
}

class Solution {
public:
    // Solution () {
          
    // }
    ll solve(int s, int k, vi& A) {
        ll prevRizz = 0;
        if(s == 3) {
            A.pb(k);
        }
        if(s == 2) {
            if(!A.empty()) reverse(all(A));
        }
        if(s == 1) {
            cyclicShift(A);
        }
        return rizziness(A);
    }

private:
    ll rizziness(const vi& v) {
        ll riz = 0;
        loop(i, 0, sz(v)) {
            riz += v[i]*(i+1);
        }
        return riz;
    }
    void cyclicShift(vi& v) {
        if (sz(v) <= 1) return;
        int last = v.back();
        rloop(i, sz(v), 1) v[i] = v[i - 1];
        v[0] = last; 
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int q;
        cin >> q;
        vi A;
        while(q--) {
            int s;
            int k = -1;
            cin >> s;
            if(s == 3) cin >> k;
            cout << sol.solve(s, k, A) << "\n";
        }
    }
    return 0;
}