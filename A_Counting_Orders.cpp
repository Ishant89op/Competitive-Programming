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

const int MOD = 1e9 + 7;

class Solution {
    int binarySearch(vi& b, int i, int& a) {
        int st = i, end = sz(b) - 1;
        while(st <= end) {
            int mid = st + (end-st)/2;
            if(b[mid] < a) {
                st = mid+1;
            } else if(b[mid] >= a) {
                end = mid - 1;
            }
        }
        return st-i;
    }

public:
    ll solve() {
        int n;
        cin >> n;
        vi a(n), b(n);
        loop(i, 0, n) {
            cin >> a[i];
        }
        loop(i, 0, n) {
            cin >> b[i];
        }
        
        int maxA = *max_element(all(a));
        int minB = *min_element(all(b));
        if(maxA <= minB) return 0;

        sort(all(a));
        sort(all(b));
        ll ans = 1;
        loop(i, 0, n) {
            int j = i;
            int seg = binarySearch(b, i, (a[i]));
            ans = (ans * seg) % MOD;
        }
        return ans % MOD;
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