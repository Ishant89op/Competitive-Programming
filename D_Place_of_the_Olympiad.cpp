#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Solution() {
       
    // }

    long long solve(long long n, long long m, long long k) {
        long double l = n*m - k;
        long double b = floor(l/n);
        long double benchLen = ceil((m-b)/(b+1));
        return benchLen;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        long long n, m, k;
        cin >> n >> m >> k;
        cout << sol.solve(n, m, k) << endl;
    }
    return 0;
}