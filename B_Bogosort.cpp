#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;

#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i >= a; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
    bool bogosort(vi& arr) {
        loop(i, 0, arr.size()) {
            loop(j, i+1, arr.size()) {
                if(j - arr[j] == i - arr[i]) return false;
                // j - i == arr[j] - arr[i]
                // j - i > 0, always
                // if arr[j] - arr[i] <= 0 == good
                // arr[j] <= arr[i]
            }
        }
        return true;
    }
public:
   // Solution() {
      
   // }

    void solve() {
        int n;
        cin >> n;
        vi A(n);
        loop(i, 0, n) {
            cin >> A[i];
        }
        sort(all(A), greater<int>());

        loop(i, 0, n) {
            cout << A[i] << (i+1 == n ? "\n" : " ");
        }
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