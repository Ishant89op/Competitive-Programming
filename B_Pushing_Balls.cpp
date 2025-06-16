#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool solve(int n, int m, vector<vector<int>>& grid) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == 1 && !checkLeft(i, j, grid) && !checkTop(i, j, grid)) 
                        return false; 
                }
            }
            return true;
        }
    
    private:
        bool checkLeft(int i, int j, vector<vector<int>>& grid) {
            for(int it = j-1; it >= 0; it--) {
                if(grid[i][it] == 0) return false;
            }
            return true;
        }
    
        bool checkTop(int i, int j, vector<vector<int>>& grid) {
            for(int it = i-1; it >= 0; it--) {
                if(grid[it][j] == 0) return false;
            }
            return true;
        }
    };
    

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for(int j = 0; j < m; j++) {
                grid[i][j] = row[j] - '0';
            }
        }
        sol.solve(n, m, grid) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}