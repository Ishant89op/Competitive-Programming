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
    bool solve(int n, vi& A) {
        // n >= 3
        sort(all(A));
        int num = A[0];
        vi B;
        loop(i, 0, n) {
            if(A[i] == 1) return true;
            if(A[i]%num != 0) B.pb(A[i]);
        }
        if(B.empty()) return true;
        num = B[0];
        loop(i, 0, sz(B)) if(B[i]%num != 0) return false;
        return true;
    }

private:
    bool isPrime(int num) {
        if (num < 2) {
            return false;
        }
        
        if (num == 2 || num == 3) {
            return true;
        }
        
        if (num % 2 == 0) {
            return false;
        }
        
        int sqrtNum = sqrt(num);
        for (int i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) {
                return false;
            }
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
        sol.solve(n, A)? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}