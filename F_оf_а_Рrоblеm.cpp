#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int result = a + b - (a + b - 2);

    cout << a % 3 << endl;
    
    return 0;
}