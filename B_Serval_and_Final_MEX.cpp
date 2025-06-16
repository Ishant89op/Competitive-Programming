#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

pair<int, vector<int>> solve(int n, vector<int>& arr) {
    pair<int, vector<int>> ans;
    return ans;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto& i : arr) cin >> i;
        pair result = solve(n, arr);
        cout << result.first << "\n";
        for(auto val : result.second) cout << val << " ";
        cout << endl;
    }
    return 0;
}