#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int makeAnagram(string a, string b) {
    map<char, int> hash;
    
    for (int i = 0; i < a.size(); i++)
        hash[a[i]]++;
        
    for (int i = 0; i < b.size(); i++)     
            hash[b[i]]--;

    int ret = 0;
    for (auto i : hash)
        ret += abs(i.second);
        
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
