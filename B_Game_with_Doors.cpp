#include <bits/stdc++.h>
using namespace std;

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
    int solve(int l, int r, int L, int R) {
        int gap = min(r, R) - max(l, L) + 1;
        int ans = gap - 1;
        if(gap <= 0) {
            ans = 1;
        } else {
            ans += (l != L);
            ans += (r != R);
        }
        return ans;        
    }
};

int main() {
    fastIO();

    int T;
    cin >> T;
    Solution sol;
    while (T--) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        cout << sol.solve(l, r, L, R) << "\n";
    }
    return 0;
}