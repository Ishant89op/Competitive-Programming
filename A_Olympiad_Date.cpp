#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Solution() {
       
    // }

    int solve(int n, vector<int>& digits) {
        int zeroes = count(digits.begin(), digits.end(), 0);
        int ones = count(digits.begin(), digits.end(), 1);
        int twos = count(digits.begin(), digits.end(), 2);
        int threes = count(digits.begin(), digits.end(), 3);
        int fives = count(digits.begin(), digits.end(), 5);
        if(zeroes < 3 || ones < 1 || twos < 2 || threes < 1 || fives < 1) return 0;

        if(digits.size() == 8) return 8;
        vector<int> main(5, 0);
        int i = 0;
        while(i < digits.size()) {
            if(condition(main)) return i;
            if(digits[i] == 0) main[0]++;
            else if(digits[i] == 1) main[1]++;
            else if(digits[i] == 2) main[2]++;
            else if(digits[i] == 3) main[3]++;
            else if(digits[i] == 5) main[4]++;
            i++;
        }
        if(condition(main)) return i;
        else return 0;
    }

private:
    bool condition(vector<int> main) {
        return (main[0] >= 3 && main[1] >= 1 && main[2] >= 2 && main[3] >= 1 && main[4] >= 1);
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
        vector<int> digits(n);
        for(auto& val : digits) cin >> val;
        cout << sol.solve(n, digits) << endl;
    }
    return 0;
}