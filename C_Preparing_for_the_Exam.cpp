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
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, b, a) for (int i = (b) - 1; i >= (a); --i)

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
    string solve(int n, int m, int k, vi& notPresent, vi& known) {
        string answer = "";
        if(k >= n) {
            rep(i, 0, m) answer += "1";
            return answer;
        } else if(k < n-1) {
            rep(i, 0, m) answer += "0";
            return answer;
        }

        vector<bool> know(n, true);
        bool done = false;
        rep(i, 0, n-1) {
            if(known[i] != i+1) {
                done = true;
                know[i] = false;
                break;
            }
        }

        if(!done) know[n-1] = false;

        rep(i, 0, m) {
            if(know[notPresent[i]-1] == true) answer += "0";
            else answer += "1";
        }

        return answer;
    }

private:
    bool isSubsequence(vi& A, vi& B) {
        int n = A.size(), m = B.size();
        int j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (A[i] == B[j]) {
                j++;
            }
        }
        return j == m;
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vi notPresent(m);
        for(auto& val : notPresent) cin >> val;
        vi known(k);
        for(auto& val : known) cin >> val;
        cout << sol.solve(n, m, k, notPresent, known) << endl;
    }
    return 0;
}