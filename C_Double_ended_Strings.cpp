#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;

#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define sz(x) x.size()
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i >= a; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
    vector<int> KMP(string s1, string s2) {
       // Knuth-Morris-Pratt Algorithm for Optimized String Matching
       // s1 = text // s2 = pattern
       // TC = O(n) // SC = O(n+m) 
        vector<int> ans, LPS(s2.size(), 0);
        int len = 0, i = 1, j = 0;
    
        while (i < s2.size()) {
            if (s2[i] == s2[len]) LPS[i++] = ++len;
            else if (len) len = LPS[len - 1];
            else LPS[i++] = 0;
        }
    
        for (i = 0; i < s1.size();) {
            if (s2[j] == s1[i]) i++, j++;
            if (j == s2.size()) ans.push_back(i - j), j = LPS[j - 1];
            else if (i < s1.size() && s2[j] != s1[i]) j ? j = LPS[j - 1] : i++;
        }
    
        return ans;
    }

    int longestCommonSubstring(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int maxLen = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }

        return maxLen;
    }
public:
   // Solution() {
      
   // }

    int solve() {
        string a, b;
        cin >> a >> b;
        int n = sz(a), m = sz(b);    
        if(n == 0) return m;
        if(m == 0) return n;
        int longestSubstring = longestCommonSubstring(a, b);
        return (n-longestSubstring) + (m-longestSubstring);
    }
};

signed main() {
    fastio

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        cout << sol.solve() << "\n";
    }
    return 0;
}