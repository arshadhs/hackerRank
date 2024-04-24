#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int q;
    cin >> q;
    
    set<int> s;
    set<int>::iterator it;

    for (int i = 0; i < q; i++ ){
     int q1, q2;
        cin >> q1 >> q2;
        

        switch (q1) {
            case 1: {
                s.insert(q2);
                break;
            }
            case 2: {
                s.erase(q2);
                break;
            }
            case 3: {
                it = s.find(q2);
                if (it == s.end())
                   cout << "No\n";
                else
                   cout << "Yes\n";
                break;
            }
        } 
        for (int i: s)           
            cout << i << " ";
    }
    
    return 0;
}