#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
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
    int solve(int n, vi& A) {
        if(n == 0 || n == 1) return 0;
        bool allSame = true;
        loop(i, 0, n-1) if(A[i] != A[i+1]) allSame = false;
        if(allSame) return 0; 
        unordered_map<int, int> freq;
        loop(i, 0, n) freq[A[i]]++;
        int maxFreq = 0;
        for(auto [key, val]: freq) maxFreq = max(maxFreq, val);
        int need = n-maxFreq;
        if(maxFreq >= need) return need+1;
        int ans = 0;
        while(need > 0) {
            if(need <= maxFreq) {
                ans += need + 1;
                break;
            }
            ans += maxFreq + 1;
            need -= maxFreq;
            maxFreq = maxFreq << 1;
        } 
        return ans;
    }
};

signed main() {
    fastIO();

    int testCases;
    cin >> testCases;
    Solution sol;
    while (testCases--) {
        int n; cin >> n; vi A(n); for(auto& i: A) cin >> i;
        cout << sol.solve(n, A) << "\n";
    }
    return 0;
}