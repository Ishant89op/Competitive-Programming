#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
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
        int ans = 0;
        rloop(i, n-1, 0) {
            if(A[i+1] <= A[i]) {
                while (A[i+1] <= A[i] && A[i] > 0) {
                    A[i] /= 2;
                    ans++;
                }                
                if(A[i] == A[i+1]) return -1;
            }
        }
        return ans;
    }
private:
    int divide2k(int x, int k) {
        return x >> k; // right shift
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