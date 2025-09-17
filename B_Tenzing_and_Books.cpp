#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define sz(x) x.size()
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i >= a; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
    // vi decimalToBinary(int n) {
    //     vi ans(32, 0);
    //     rloop(i, 31, 0) {
    //         ans[i] = (n & 1);
    //         n >>= 1;
    //         if(n == 0) break;
    //     }
    //     return ans;
    // }

    // bool check(const vi& xB, const vi& k) {
    //     loop(i, 0, sz(k)) {
    //         if (xB[i] != k[i]) return false;
    //     }
    //     return true;
    // }

public:
    bool solve() {
        int n, x;
        cin >> n >> x;
        vi a(n), b(n), c(n);
        loop(i, 0, n) {
            cin >> a[i];
        }
        loop(i, 0, n) {
            cin >> b[i];
        }
        loop(i, 0, n) {
            cin >> c[i];
        }
        if(x == 0) return true;

        // vi knowledge(32, 0);
        // vi xB = decimalToBinary(x);

        // bool getA = true, getB = true, getC = true;

        // while ((getA && !a.empty()) || (getB && !b.empty()) || (getC && !c.empty())) {
        //     // stack A
        //     if (getA) {
        //         if (a.empty()) {
        //             getA = false;
        //         } else {
        //             int an = a.top();
        //             vi aNow = decimalToBinary(an);
        //             bool conflict = false;
        //             vi temp = knowledge;

        //             loop(i, 0, 32) {
        //                 if (xB[i] == 0 && aNow[i] == 1) {
        //                     conflict = true;
        //                     break;
        //                 } else {
        //                     temp[i] = (knowledge[i] | aNow[i]);
        //                 }
        //             }

        //             if (conflict) {
        //                 a.pop();
        //                 getA = false;
        //             } else {
        //                 knowledge = temp;
        //                 a.pop();
        //             }
        //         }
        //     }

        //     if (check(xB, knowledge)) return true;
        //     // stack B
        //     if (getB) {
        //         if (b.empty()) {
        //             getB = false;
        //         } else {
        //             int bn = b.top();
        //             vi bNow = decimalToBinary(bn);
        //             bool conflict = false;
        //             vi temp = knowledge;

        //             loop(i, 0, 32) {
        //                 if (xB[i] == 0 && bNow[i] == 1) {
        //                     conflict = true;
        //                     break;
        //                 } else {
        //                     temp[i] = (knowledge[i] | bNow[i]);
        //                 }
        //             }

        //             if (conflict) {
        //                 b.pop();
        //                 getB = false;
        //             } else {
        //                 knowledge = temp;
        //                 b.pop();
        //             }
        //         }
        //     }
            
        //     if (check(xB, knowledge)) return true;
        //     // stack C
        //     if (getC) {
        //         if (c.empty()) {
        //             getC = false;
        //         } else {
        //             int cn = c.top();
        //             vi cNow = decimalToBinary(cn);
        //             bool conflict = false;
        //             vi temp = knowledge;

        //             loop(i, 0, 32) {
        //                 if (xB[i] == 0 && cNow[i] == 1) {
        //                     conflict = true;
        //                     break;
        //                 } else {
        //                     temp[i] = (knowledge[i] | cNow[i]);
        //                 }
        //             }

        //             if (conflict) {
        //                 c.pop();
        //                 getC = false;
        //             } else {
        //                 knowledge = temp;
        //                 c.pop();
        //             }
        //         }
        //     }

        //     if (check(xB, knowledge)) return true;
        // }

        // return check(xB, knowledge);

        int knowledge = 0;

        // a
        loop(i, 0, n) {
            if ((x | a[i]) != x) break;
            knowledge |= a[i];
        }

        // b
        loop(i, 0, n) {
            if ((x | b[i]) != x) break;
            knowledge |= b[i];
        }

        // c
        for (int i = 0; i < n; i++) {
            if ((x | c[i]) != x) break;
            knowledge |= c[i];
        }

        return (knowledge == x);
    }
};

signed main() {
    fastio

    int T = 1;
    cin >> T;
    Solution sol;

    while (T--) {
        sol.solve() ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}