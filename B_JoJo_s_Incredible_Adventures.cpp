#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair
#define sz(x) x.size()
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b-1; i >= a; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
    // void cyclicShiftRight(string& s) {
    //     int n = s.size();
    //     if (n <= 1) return;
    //     char lastEle = s[n - 1];
    //     rloop (i, n, 1) {
    //         s[i] = s[i - 1];
    //     }
    //     s[0] = lastEle;
    // }

    bool checkAllZeroes(string& s) {
        loop(i, 0, sz(s)) {
            if(s[i] == '1') {
                return false;
            }
        }
        return true;
    }

    bool checkAllOnes(string& s) {
        loop(i, 0, sz(s)) {
            if(s[i] == '0') return false;
        }
        return true;
    }

    int maxConsecutiveOnesInCyclicWay(int n, string& s) {
        int maxConsecOnes = 0, consecOnes = 0;

        loop(i, 0, n) {
            if(s[i] == '0') {
                maxConsecOnes = max(maxConsecOnes, consecOnes);
                consecOnes = 0;
            } else {
                consecOnes++;
            }
        }
        maxConsecOnes = max(maxConsecOnes, consecOnes);
        consecOnes = 0;
        int i = 0, j = n-1;
        if(s[0] == '1' && s[n-1] == '1') {
            while(i < j && s[i] == '1') {
                consecOnes++;
                i++;
            }
            while(j > i && s[j] == '1') {
                consecOnes++;
                j--;
            }
        }
        maxConsecOnes = max(maxConsecOnes, consecOnes);
        return maxConsecOnes;
    }

    int maxConsecutiveOnes(int n, string& s) {
        int maxConsecOnes = 0, consecOnes = 0;
        loop(i, 0, n) {
            if(s[i] == '0') {
                maxConsecOnes = max(maxConsecOnes, consecOnes);
                consecOnes = 0;
            } else {
                consecOnes++;
            }
        }
        maxConsecOnes = max(maxConsecOnes, consecOnes);
        return maxConsecOnes;
    }

public:
    ll solve() {
        string s;
        cin >> s;
        ll n = sz(s);

        if(checkAllZeroes(s)) return 0;
        if(checkAllOnes(s)) return ll(n*n);
        // vvi a(n, vi(n, 0));
        // loop(j, 0, n) {
        //     loop(i, 0, n) a[j][i] = s[i]-'0';
        //     cyclicShiftRight(s);
        // }
        // int ul = 0, ur = n-1, lu = 0, ld = n-1;
        ll ans = 0;

        ld mcoc = maxConsecutiveOnesInCyclicWay(n, s);

        ans = ceil((mcoc + 1.00)/2.00) * floor((mcoc + 1.00)/2.00);

        return ans;
    }
};

signed main() {
    fastio

    int T = 1;
    cin >> T;
    Solution sol;

    while (T--) {
        cout << sol.solve() << "\n";
    }
    return 0;
}