#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v;
            
    for (int i = 0; i < n ; i++) {
        int k;
        cin >> k;
        vector<int> v1;
        for (int j = 0; j < k ; j++) {
            int x;
            cin >> x;
            v1.push_back(x);
        }
        v.push_back(v1);
    }
    
    for (int i = 0; i < n ; i++) {
            int x, y;
            cin >> x >> y;
            cout << v[x][y];
    }
    
    return 0;
}