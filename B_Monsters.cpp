#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define loop(i, a, b) for (int i = (a); i < (b); ++i)
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
    void solve() {
        long long n, k;
        cin >> n >> k;
        vector<pair<long long, long long> > health_points(n);
        for (long long i = 0; i < n; i++) // n
        {
            long long x;
            cin >> x;
            health_points[i] = { x, i + 1 };
        }
 
        for (long long i = 0; i < n; i++) // n
        {
            health_points[i].first = health_points[i].first % k;
            if (health_points[i].first == 0)
                health_points[i].first = k;
        }
 
        sort(health_points.begin(), health_points.end(), [&](pair<long long, long long> a, pair<long long, long long> b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        }); // nlogn
 
        for (auto it : health_points) // n
            cout << it.second << " ";
        cout << endl;
    }
};

signed main() {
    fastIO();

    int testCases;
    cin >> testCases;
    Solution sol;
    while (testCases--) {
        sol.solve();
    }
    return 0;
}