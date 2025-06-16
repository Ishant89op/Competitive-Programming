#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
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
    void solve(int n) {
        if(n <= 4) {
            cout << "-1\n";
            return;
        }
        int even = 2, odd = 1, fEven = 4, fOdd = 5;
        vi ans(n, -1);
        if(n%2 == 0) {
            ans[n/2-1] = fEven;
            ans[n/2] = fOdd;
            loop(i, 0, n/2-1) {
                if(even == fEven) even += 2;
                if(odd == fOdd) odd += 2;
                ans[i] = even;
                even += 2;
                ans[n/2+i+1] = odd;
                odd += 2;
            }
        } else {
            ans[n/2] = fOdd;
            ans[n/2-1] = fEven;
            loop(i, 0, n/2) {
                if(even == fEven) even += 2;
                if(odd == fOdd) odd += 2;
                if(i != n/2-1) ans[i] = even;
                even += 2;
                ans[n/2+i+1] = odd;
                odd += 2;
            }
        }
        for(auto i: ans) cout << i << " ";
        cout << "\n";
    }
private:
    bool isComposite(int n) {
        if (n <= 3) return false;
        if (n % 2 == 0 || n % 3 == 0) return true;
        for (int i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return true;
        return false;
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
        sol.solve(n);
    }
    return 0;
}