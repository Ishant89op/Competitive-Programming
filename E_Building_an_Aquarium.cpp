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
    long long totalWater(vll& a, long long& h) {
        long long ans = 0;
        loop(i, 0, sz(a)) {
            ans += max(0LL, h - a[i]);
        }
        return ans;
    }

    long long binarySearch(long long& low, long long& upp) {
        return (low + ((upp-low)/2));
    }
public:
    long long solve() {
        int n, x;
        cin >> n >> x;
        vll a(n);

        loop(i, 0, n) {
            cin >> a[i];
        }

        long long lowerBound = 1;
        long long upperBound = *max_element(all(a)) + x;;
        long long ans = 1;
        while (lowerBound <= upperBound) {
            long long mid = (lowerBound + ((upperBound-lowerBound)/2));
            long long w = totalWater(a, mid);

            
            if (w <= x) {
                ans = mid;            
                lowerBound = mid + 1;
            } else {
                upperBound = mid - 1; 
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