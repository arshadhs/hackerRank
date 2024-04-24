#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    string numStr[10]{"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    int a, b;
    cin >> a >> b;
    
    cout << numStr[a] << "\n";
    cout << numStr[b] << "\n";
    cout << ((a%2 == 0) ? "even" : "odd") << "\n";
    cout << ((b%2 == 0) ? "even" : "odd") << "\n";
    
    return 0;
}|