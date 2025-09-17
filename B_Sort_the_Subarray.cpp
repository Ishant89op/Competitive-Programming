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
    pii solve() {
        int n;
        cin >> n;
        vi a(n), a_(n);
        loop(i, 0, n) {
            cin >> a[i];
        } 
        loop(i, 0, n) {
            cin >> a_[i];
        }
        pii ans = {1, 1};
        // vi temp = a;
        // loop(i, 0, n) {
        //     loop(j, i, n) {
        //         sort(temp.begin()+i, temp.begin()+j+1);
        //         if(temp == a_ && ans.second-ans.first < j-i) {
        //             ans = {i+1, j+1};
        //         } else {
        //             temp = a;
        //         }
        //     }
        // }
        int i = 0, j = n-1;
        while (i < n && a[i] == a_[i]) i++;
        while (j >= 0 && a[j] == a_[j]) j--;

        while(i > 0 && a_[i] >= a[i-1]) i--;
        while(j < n-1 && a_[j] <= a[j+1]) j++;

        ans = {i+1, j+1};

        return ans;
    }
};

signed main() {
    fastio

    int T = 1;
    cin >> T;
    Solution sol;

    while (T--) {
        pii ans = sol.solve();
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}