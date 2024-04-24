#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin>> num;
        v.push_back(num);
    }
    
    int q;
    cin >> q;
    vector<int>::iterator it;
    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;    
              
        it = std::lower_bound(v.begin(), v.end(), y);
        if (*it == y) {
            cout << "Yes " << it - v.begin() + 1 << "\n";
        }
        else {
            cout << "No " << it - v.begin() + 1 << "\n";
        }
        
        
    }
    
    return 0;
}
