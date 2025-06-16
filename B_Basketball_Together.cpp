#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i >= a; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
public:
    // Solution() {
       
    // }

    int solve() {
        int N, D;
        cin >> N >> D;
        vi A(N);
        for(auto& i: A) cin >> i;
        int ans = 0;
        sort(all(A));
        int i = 0, j = N - 1;
        while(i <= j) {
            int x = D / A[j];
            if(i + x <= j) {
                i += x;
                ans++;
            }
            j--;
        }
        return ans;
    }    
};

signed main() {
    fastio

    int T = 1;
    Solution sol;

    while (T--) {
        cout << sol.solve() << "\n";
    }
    return 0;
}