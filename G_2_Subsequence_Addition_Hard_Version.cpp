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
#define rloop(i, b, a) for (int i = b-1; i >= a; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {

public:
    bool solve() {
        int n;
        cin >> n;
        vi c(n);
        loop(i, 0, n) {
            cin >> c[i];
        }
        if(n == 1) return c[0] == 1;
        int ones = count(all(c), 1);
        if(ones < 2) return false;
        sort(all(c));
        ll sum = 1;
        loop(i, 1, n) {
            if(c[i] > sum) return false;
            sum += c[i];
        }
        return true;
    }
};

signed main() {
    fastio

    int T = 1;
    cin >> T;
    Solution sol;

    while (T--) {
        sol.solve() ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}