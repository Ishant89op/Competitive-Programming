#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define all(v) v.begin(), v.end()
#define loop(i, a, b) for (int i = a; i < b; i++)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
public:
    ll solve() {
        int n, k;
        cin >> n >> k;
        vi a(n);
        loop(i, 0, n) cin >> a[i];
        if (k >= n) return 0;

        sort(all(a));

        // Build prefix sum
        vll prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + a[i - 1];
        }

        ll ans = 0;
        for (int m = 0; m <= k; m++) {
            if (2 * m > n) continue; 
            int left = 2 * m;
            int right = n - (k - m);
            if (left > right) continue;
            ll segmentSum = prefix[right] - prefix[left];
            ans = max(ans, segmentSum);
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