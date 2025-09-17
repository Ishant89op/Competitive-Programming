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
    int solve() {
        int n;
        cin >> n;

        int ans = 0;
        while(n >= 100) {
            n -= 100;
            ans++;
        }
        while(n >= 20) {
            n -= 20;
            ans++;
        }
        while(n >= 10) {
            n -= 10;
            ans++;
        }
        while(n >= 5) {
            n -= 5;
            ans++;
        }
        while(n >= 1) {
            n--;
            ans++;
        }
        return ans;
    }
};

signed main() {
    fastio

    int T = 1;
    Solution sol;

    while (T--) {
        cout << sol.solve() << "\n";
    }
    return 0;
}