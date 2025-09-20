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
    void solve() {
        int n;
        cin >> n;
        int firstSeg = n, secondSeg = 1;
        while(firstSeg >= 1) {
            cout << firstSeg-- << " ";
        }
        cout << n << " ";
        while(secondSeg < n) {
            cout << secondSeg++ << " ";
        }
        cout << "\n";
    }
};

signed main() {
    fastio

    int T = 1;
    cin >> T;
    Solution sol;

    while (T--) {
        sol.solve();
    }
    return 0;
}