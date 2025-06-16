#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int>& interest) {
    if(interest[0] > 15 || n == 0) return 15;
    if(n == 1) return interest[0]+15;
    int i = 1;
    while(i < n) {
        if(interest[i]-interest[i-1] > 15) return interest[i-1]+15;
        i++;
    }
    if(90-interest[n-1] > 15) return interest[n-1]+15;
    return 90;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> interest(n);
    for(auto& val : interest) cin >> val;
    cout << solve(n, interest) << endl;
    return 0;
}