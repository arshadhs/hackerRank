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
    
    vector <int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    int x;
    cin >> x;    
    v.erase(v.begin()+x-1);
    
    int a, b;
    cin >> a >> b;
    
    //for (int i = 0; i < v.size(); i++) {
    // for(vector<int>::iterator it = v.begin(); it!=v.end()) {
    //     if (it->at(i) >= a && it->at(i) <= b)
    //         v.erase(it);
    // }
    v.erase(v.begin() + a - 1, v.ebgin() + b - 1);
    
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";
       
    return 0;
}