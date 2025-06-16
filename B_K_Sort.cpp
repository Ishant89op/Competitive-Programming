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
    ll solve(int n, vi& A) {
        if(n == 0 || n == 1 || checkSorted(A)) return 0;
        vi B(n, 0);
        int ele = A[0];
        B[0] = A[0];
        loop(i, 1, n) {
            ele = max(ele, A[i]); 
            B[i] = (ele);
        }
        vi C(n, 0);
        ll sumOfC = 0;
        int maxC = 0;
        loop(i, 0, n) {
            C[i] = (B[i]-A[i]);
            sumOfC += C[i];
            maxC = max(maxC, C[i]);
        }
        return sumOfC + maxC;
    }

private:
    bool checkSorted(vi& A) {
        loop(i, 0, sz(A)-1) {
            if(A[i] > A[i+1]) return false;
        }
        return true;
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n;
        cin >> n;
        vi A(n);
        for(auto& i: A) cin >> i;
        cout << sol.solve(n, A) << "\n";
    }
    return 0;
}