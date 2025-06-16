#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Solution() {
       
    // }

    bool solve(int n, vector<int>& res, vector<int>& need) {
        // for(int i = 0; i < n; i++) {
        //     while(res[i] < need[i]) {
        //         operation(i, res);
        //     }
        // }
        // return condition(res, need);

        int needyIndex = -1;
        int minExtra = INT_MAX;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(res[i] < need[i]){
                needyIndex = i;
                count++;
            } else {
                minExtra = min(minExtra, res[i]-need[i]);
            }
            if(count == 2) return false;
        }
        if(count == 0) return true;
        int extraNeeded = need[needyIndex] - res[needyIndex];

        return (extraNeeded <= minExtra && minExtra < INT_MAX);
    }

private:
    bool condition(vector<int>& res, vector<int>& need) {
        for(int i = 0; i < res.size(); i++) {
            if(res[i] < need[i]) return false;
        }
        return true;
    }

    void operation(int idx, vector<int>& res) {
        res[idx]++;
        for(int i = 0; i < res.size(); i++) {
            if(i==idx) continue;
            if(res[i] > 0) res[i]--;
        }
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
        vector<int> res(n), need(n);
        for(auto& val : res) cin >> val;
        for(auto& val : need) cin >> val;            
        sol.solve(n, res, need) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}