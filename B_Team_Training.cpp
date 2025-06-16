#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Solution() {
       
    // }

    int solve(int n, int x, vector<int>& strn) {
        sort(strn.begin(), strn.end(), greater<int>());
        int ans = 0;
        int size = 0;
        for(int i = 0; i < n; i++) {
            size++;
            if(size * strn[i] >= x) {
                ans++;
                size = 0;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> strn(n);
        for(auto& val : strn) cin >> val;
        cout << sol.solve(n, x, strn) << endl;
    }
    return 0;
}