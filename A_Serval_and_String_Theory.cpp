#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

bool universalOrNot(int n, int k, string& s) {
    // A string r consisting only of lowercase Latin letters is called universal if and only if r is lexicographically smaller than the reversal† of r.
    if(n==1 || n==0) return false;
    string revS = s;
    reverse(revS.begin(), revS.end());
    if(s < revS) return true;
    set<char> st(s.begin(), s.end());
    int diffChar = st.size();
    if(diffChar > 1 && k > 0) return true;
    return false;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        universalOrNot(n, k, s) ? cout << "YES" << endl : cout << "NO" << endl;
    }
}