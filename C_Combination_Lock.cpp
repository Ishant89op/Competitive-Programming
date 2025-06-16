#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Solution() {
       
    // }

    void solve(int n) {
        if(n%2 == 0) {
            cout << "-1" << endl;
            return;
        }
        for (int i = n; i > 0; i--) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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