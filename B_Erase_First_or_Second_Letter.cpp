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
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i >= a; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
    void countSubs(unordered_set<string>& ans, string& s) {
        if(s.length() < 2) return;

        string fR = s.substr(1);
        if(ans.insert(fR).second) {
            countSubs(ans, fR);
        }
        
        string sR = s.substr(0, 1) + s.substr(2);
        if(ans.insert(sR).second) {
            countSubs(ans, sR);
        }
    }
public:
   // Solution() {
      
   // }

    ll solve() {
        int n; string s;
        cin >> n >> s;
        unordered_map<char, int> freq;
        ll c = 0;
        vll dist(n);
        loop(i, 0, n) {
            freq[s[i]]++;
            if(freq[s[i]] == 1) {
                c++;
            }
            dist[i] = c;
        }
        ll ans = 0;
        loop(i, 0, n) {
            ans += dist[i];
        }
        return ans;
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