#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Solution() {
       
    // }

    bool solve(long long x, long long y, long long a) {
        long long dep = 2 * a + 1;
        long long cDep = 2 * (x + y);
        long long c = dep / cDep;
        long long rDep = dep - c * cDep;

        if(2 * x > rDep) return false;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        long long x, y, a;
        cin >> x >> y >> a;
        sol.solve(x, y, a) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}